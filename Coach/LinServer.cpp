#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <netinet/in.h>
#include <resolv.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <math.h>
#include <cstring>
#include "messages_robocup_ssl_wrapper.pb.h"
#include "messages_robocup_ssl_detection.pb.h"
#include "messages_robocup_ssl_geometry.pb.h"
#include "netraw.h"
#include "grSim_Packet.pb.h"
#include "grSim_Commands.pb.h"
#include "grSim_Replacement.pb.h"
#include "Robot.h"
#include "Goalie.h"

#define PI 3.14159265 
#define goal_x 3200
#define goal_y 0
#define goalie_x  2900
#define goalie_y1 370
#define goalie_y2 -380

Robot* Ybots [5];
Robot* Bbots [5];
int count = 0;
bool ready = true;

float distance(float x1, float y1, float x2, float y2){
	return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}

void centerBall(){
	grSim_Packet packet;	

	grSim_BallReplacement* replace = packet.mutable_replacement()->mutable_ball();
	int x1 = rand();
	int y1 = rand();
	
	double x = (double(x1%5000) + -2500.0)/1000.0;
	double y = (double(y1%3000) + -1500.0)/1000.0;
	
	replace->set_x(x);
	replace->set_y(y);
	replace->set_vx(0);
	replace->set_vy(0);

	
	std::string s;
    	packet.SerializeToString(&s);
	Net::UDP udpsocket;
	Net::Address _addr;
	_addr.setHost("127.0.0.1",20011);
	udpsocket.open();
    	udpsocket.send((void*) s.data(), s.size(), _addr);
}
	
void* SocketHandler(void*);

int main(int argv, char** argc){

	for(int i = 0; i < 5; i++){
		Ybots[i] = new Robot(i, true);
		Bbots[i] = new Robot(i, false);
	}
	Ybots[4] = new Goalie(4,true);
	ready = false;

    int host_port= 30015;

    struct sockaddr_in my_addr;

    int hsock;
    int * p_int ;
    int err;

    socklen_t addr_size = 0;
    int* csock;
    sockaddr_in sadr;
    pthread_t thread_id=0;


    hsock = socket(AF_INET, SOCK_STREAM, 0);
    if(hsock == -1){
        printf("Error initializing socket %d\n", errno);
        goto FINISH;
    }
    
    p_int = (int*)malloc(sizeof(int));
    *p_int = 1;
        
    if( (setsockopt(hsock, SOL_SOCKET, SO_REUSEADDR, (char*)p_int, sizeof(int)) == -1 )||
        (setsockopt(hsock, SOL_SOCKET, SO_KEEPALIVE, (char*)p_int, sizeof(int)) == -1 ) ){
        printf("Error setting options %d\n", errno);
        free(p_int);
        goto FINISH;
    }
    free(p_int);

    my_addr.sin_family = AF_INET ;
    my_addr.sin_port = htons(host_port);
    
    memset(&(my_addr.sin_zero), 0, 8);
    my_addr.sin_addr.s_addr = INADDR_ANY ;
    
    if( bind( hsock, (sockaddr*)&my_addr, sizeof(my_addr)) == -1 ){
        fprintf(stderr,"Error binding to socket, make sure nothing else is listening on this port %d\n",errno);
        goto FINISH;
    }
    if(listen( hsock, 10) == -1 ){
        fprintf(stderr, "Error listening %d\n",errno);
        goto FINISH;
    }

    //Now lets do the server stuff

    addr_size = sizeof(sockaddr_in);
    
    while(true){
        printf("waiting for a connection\n");
        csock = (int*)malloc(sizeof(int));
        if((*csock = accept( hsock, (sockaddr*)&sadr, &addr_size))!= -1){
            printf("---------------------\nReceived connection from %s\n",inet_ntoa(sadr.sin_addr));
            pthread_create(&thread_id,0,&SocketHandler, (void*)csock );
            pthread_detach(thread_id);
        }
        else{
            fprintf(stderr, "Error accepting %d\n", errno);
        }
    }
    
FINISH:
;
}

void* SocketHandler(void* lp){
    int *csock = (int*)lp;

    char buffer[1024];
    int buffer_len = 1024;
    int bytecount;

    memset(buffer, 0, buffer_len);
    if((bytecount = recv(*csock, buffer, buffer_len, 0))== -1){
       // fprintf(stderr, "Error receiving data %d\n", errno);
        //goto FINISH
    }
    printf("Received bytes %d\nReceived string \"%s\"\n", bytecount,buffer);
    
	
    SSL_WrapperPacket packet;
	
	std::string message = std::string(buffer, bytecount);

    int mode = packet.ParseFromString(message);

    SSL_DetectionFrame packetFrame;

    packetFrame = packet.detection();
    SSL_GeometryData packetGeo = packet.geometry();
    SSL_GeometryFieldSize packetField = packetGeo.field();

	printf("\nParse status: %d",mode);


    //printf("\n%d",packetField.field_length());
    //printf("\n%d",packetField.field_width());
	
    printf("\nNumber of b: %d",packet.detection().balls_size());
    printf("\nNumber of r: %d",packet.detection().robots_yellow_size());
    printf("\nTimestamp: %f\n",packetFrame.t_sent());
	SSL_DetectionBall ball;
    if(packetFrame.balls_size() > 0){
    	
    	ball = packetFrame.balls(0);
    	float x = ball.x();
    	float y = ball.y();
    	float z = ball.z();
    	printf("x: %f, y: %f, z: %f",x,y,z);
    }
    for(int i = 0; i < packet.detection().robots_blue_size(); i++){
	SSL_DetectionRobot packetR;
	packetR = packet.detection().robots_blue(i);
	float x = packetR.x();
	float y = packetR.y();
	float orientation = packetR.orientation();
	printf("\nRobot B id %d, x: %f, y: %f, orientation: %f",i,x,y,orientation);
    }
	
	if(ball.x() > 3000 || ball.x() < -3000 || ball.y() > 2000 || ball.y() < -2000){
		//sleep(3);
		usleep(500*1000);
		//if(ball.x() > 3000 || ball.x() < -3000 || ball.y() > 2000 || ball.y() < -2000){
			centerBall();
		//}
	}
	for(int i = 0; i < packet.detection().robots_yellow_size(); i++){
	SSL_DetectionRobot packetR;
	packetR = packet.detection().robots_yellow(i);
	float x = packetR.x();
	float y = packetR.y();
	float orientation = packetR.orientation();
	printf("\nRobot Y id %d, x: %f, y: %f, orientation: %f",i,x,y,orientation);
    }
	
	if(ball.x() > 3000 || ball.x() < -3000 || ball.y() > 2000 || ball.y() < -2000){
		//sleep(1);
		if(ball.x() > 3000 || ball.x() < -3000 || ball.y() > 2000 || ball.y() < -2000){
			//centerBall();
		}
	}


	//updates info for all bots
	for(int i = 0; i < 5; i++){
		Ybots[i]->Update(&packetFrame);
		Bbots[i]->Update(&packetFrame);
	}
	
	for(int i = 0; i < 3; i++){
		Ybots[i]->Teleport(10+i,10+1);
		Bbots[i]->Teleport(10,10+i);
	}
	//Ybots[3]->Teleport(11,-12);
	//Bbots[4]->Prepare(ball.x(),ball.y(),1.5,5,3025,0);
	//if(ready){
	//Ybots[0]->Teleport(2,-1);
	//Ybots[1]->Teleport(1,-0.5);
	//Ybots[2]->Teleport(1,0.5);
	//Ybots[3]->Teleport(2,1);
	//ready = false;
	//}
	
	//Ybots[4].Move(1000,1000,1);
	//Ybots[4].Rotate(1.57);
	printf("\nCount is %d",count++);
	//Ybots[4].Kick(5);

	
	//role assignment
	Robot* shooterBotB = NULL;
	Robot* passerBotB = NULL;
	Robot* shooterBotY = NULL;
	Robot* passerBotY = NULL;

	/*if(Bbots[4]->x < Bbots[3]->x){
		Bbots[4]->shooter = false;
		Bbots[3]->shooter = true;
		shooterBot = Bbots[3];
		passerBot = Bbots[4];
	}
	else{
		Bbots[4]->shooter = true;
		Bbots[3]->shooter = false;
		shooterBot = Bbots[4];
		passerBot = Bbots[3];
	}*/

//Bbots[3]->PathTo(1500,200,1.5);
//Bbots[4]->Prepare(ball.x(),ball.y(),1.5,5,3025,0);

		//bbots
		if(Bbots[3]->x > Bbots[4]->x){
			Bbots[3]->shooter = true;
			Bbots[4]->shooter = false;
			shooterBotB = Bbots[3];
			passerBotB = Bbots[4];
		}
		else{
			Bbots[4]->shooter = true;
			Bbots[3]->shooter = false;
			shooterBotB = Bbots[4];
			passerBotB = Bbots[3];
		}
		/*
		//ybots
		if(Ybots[3]->x < Ybots[4]->x){
			Ybots[3]->shooter = true;
			Ybots[4]->shooter = false;
			shooterBotY = Ybots[3];
			passerBotY = Ybots[4];
		}
		else{
			Ybots[4]->shooter = true;
			Ybots[3]->shooter = false;
			shooterBotY = Ybots[4];
			passerBotY = Ybots[3];
		}
*//*
		if(distance(ball.x(),ball.y(),shooterBotB->x,shooterBotB->y) > 600){
			passerBotB->Pass(shooterBotB->id,shooterBotB->yellow,1.5);
			shooterBotB->PathTo(1500,200,1.5);
			shooterBotB->velA = 0;
		}
		else{
			shooterBotB->Prepare(ball.x(),ball.y(),1.5,5,3025,0);
			passerBotB->Stop();
		}
/*
		if(distance(ball.x(),ball.y(),shooterBotY->x,shooterBotY->y) > 600){
			passerBotY->Pass(shooterBotY->id,shooterBotY->yellow,1.5);
			shooterBotY->PathTo(-1500,-200,1.5);
			shooterBotY->velA = 0;
		}
		else{
			shooterBotY->Prepare(ball.x(),ball.y(),1.5,5,-3025,0);
			passerBotY->Stop();
		}
*/
	Ybots[3]->Prepare(ball.x(), ball.y(), 1.5, 8, -3025, 0);
	Bbots[3]->Prepare(ball.x(), ball.y(), 1.5, 8, 3025, 0);


	//static_cast<Goalie*>(Ybots[4])->Update(&packetFrame);
	//static_cast<Goalie*>(Ybots[4])->Defend(ball.x(),ball.y());



	static_cast<Goalie*>(Ybots[4])->Update(&packetFrame);
	static_cast<Goalie*>(Ybots[4])->Defend(ball.x(),ball.y());

	static_cast<Goalie*>(Bbots[4])->Update(&packetFrame);
	static_cast<Goalie*>(Bbots[4])->Defend(ball.x(),ball.y());


	
	
	close(*csock);


FINISH:
    free(csock);
    return 0;
}
