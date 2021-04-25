#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct { //큐의 노드타입
	int id; 
	int arrival_time;
	int service_time; 
	int ATM_num; 
	int VIP; 
	struct QUEUENODE* link; 
}QUEUENODE;
typedef struct { //큐ADT 구현
	int line; 
	QUEUENODE* front, * rear; 
}LinkedQueueType;
//초기화 함수
void init(LinkedQueueType* q)
{
	q->front = q->rear = NULL;
}
//공백 상태 검출 함수
int is_empty(LinkedQueueType* q) { 
	return(q->front == NULL);
} 
//대기줄 앞 삽입함수(VIP)
void add_front(LinkedQueueType* q, QUEUENODE customer) {
	QUEUENODE* temp = (QUEUENODE*)malloc(sizeof(QUEUENODE));
	temp->id = customer.id;
	temp->arrival_time = customer.arrival_time;
	temp->service_time = customer.service_time;
	temp->ATM_num = customer.ATM_num;
	temp->VIP = customer.VIP;
	temp->link = NULL;
	if (is_empty(q)) { //큐가 공백이면
		q->front = temp;
		q->rear = temp;
		printf("%d시 %d분 - %d번 고객(%d분 소요)이 %d번 ATM에서 서비스를 시작함!!\n", 9+(customer.arrival_time)/60, (customer.arrival_time) % 60,customer.id, customer.service_time, customer.ATM_num);
	}
	else { //큐가 공백이 아니면
		temp->link = q->front->link; //가장 첫 번째는 업무 중이므로 두 번째에 삽입
		q->front->link = temp;
		if (q->front == q->rear) q->rear = temp;
	}
}
//대기줄 끝 삽입함수(일반적)
void enqueue(LinkedQueueType* q, QUEUENODE customer) {
	QUEUENODE* temp = (QUEUENODE*)malloc(sizeof(QUEUENODE));//새로 추가
	temp->id = customer.id;
	temp->arrival_time = customer.arrival_time;
	temp->service_time = customer.service_time;
	temp->ATM_num = customer.ATM_num;
	temp->VIP = customer.VIP;
	temp->link = NULL;
	if (is_empty(q)) { //큐가 공백이면
		q->front = temp;
		q->rear = temp;
		printf("%d시 %d분 - %d번 고객(%d분 소요)이 %d번 ATM에서 서비스를 시작함!!\n", 9 + (customer.arrival_time) / 60, (customer.arrival_time) % 60, customer.id, customer.service_time, customer.ATM_num);
	}
	else { //큐가 공백이 아니면
		q->rear->link = temp;
		q->rear = temp;
	}

}
//줄 앞 삭제함수(일반적)
void dequeue(LinkedQueueType* q) {
	printf("%d번 ATM에서 %d번 고객 업무 처리 완료\n", q->front->ATM_num, q->front->id);
	QUEUENODE* temp = q->front;
	int data;
	if (is_empty(q)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		data = temp->id;
		q->front = q->front->link;
		if (q->front == NULL)
			q->rear = NULL;
		free(temp);
	}
	q->line = (q->line) - 1;
}
//줄 이탈 함수
void delete(LinkedQueueType* q, QUEUENODE* pre) {
	QUEUENODE* temp = pre->link;
	if (temp == q->rear) {
		pre->link = NULL;
		q->rear = pre;
		free(temp);
	}
	else {
		pre->link = temp->link;
		free(temp);
	}
	q->line = (q->line) - 1; //대기인원 한 명 감소
}
//VIP판별 함수
int is_VIP(){
	if ((rand() % 10) == 0) return 1;//0~9까지의 숫자 중에 0이 걸리면 VIP. (10%의 확률)
	else return 0;
}
//ATM선택 함수
int which_ATM(int one, int two, int three) { //기기 1, 2, 3 의 대기 인원 수
	if ((one < two) && (one < three)) return 0; //1이 제일 적을 때
	else if ((two < one) &&( two < three)) return 1; //2가 제일 적을 때
	else if ((three < one) && (three < two)) return 2; //3이 제일 적을 때
	else if ((one == two) &&( two < three)) return (rand() % 2); //3이 가장 많고 1, 2의 대기 인원이 같을 때
	else if ((one == three) && (three < two)) { //2가 가장 많고 1, 3의 대기 인원이 같을 때
		if (rand() % 2 == 0) return 0;
		else return 2;
	}
	else if (two == three && three < one) return (rand() % 2 + 1);//1이 가장 많고 2, 3의 대기 인원이 같을 때
	else return (rand() % 3);//세 기기 모두 대기인원이 같을 경우
}
//ATM프린트 함수
void print_queue(LinkedQueueType* q) {
	QUEUENODE* p;
	printf("start-> ");
	for (p = q->front; p != NULL; p = p->link) {
		printf("%d->", p->id);
	}
	printf(" end\n");
}
//소수 판별 함수
int is_prime(int a) {
	if ((a == 0) || (a == 1)) return 0;
	if (a == 2) return 1;
	for (int i = 2; i < a; i++) {
		if (a % i == 0) return 0;
	}
	return 1;
}


int main(void) { //업무 처리가 끝나는 것보다 손님이 들어오는 것이 먼저이며, 줄의 가장 앞 사람은 현재 업무를 처리 중임.

	LinkedQueueType ATM[3]; init(&ATM[0]);	init(&ATM[1]);	init(&ATM[2]); //ATM 세 개 만들고 초기화
	ATM[0].line = 0, ATM[1].line = 0, ATM[2].line = 0; //ATM1, 2, 3의 현재 대기 인원
	int minutes = 120; //9시 0분부터 10시 59분까지 총 120분
	int total_wait = 0, total_customers = 0;
	srand((unsigned)time(NULL));
	for (int clock = 0; clock < minutes; clock++) {
		printf("\n현재 시각: %d시 %d분\n", 9 + clock / 60, clock % 60);
		QUEUENODE customer; //지금 들어온 손님
		customer.id = clock % 60; //고객의 아이디는 도착한 시간(분)
		customer.arrival_time = clock; //도착 시간
		customer.service_time = rand() %9+1; //소요되는 서비스 시간(2~10분)
		customer.ATM_num = which_ATM(ATM[0].line, ATM[1].line, ATM[2].line); //ATM기기 선택
		customer.VIP = is_VIP();
		printf("%d시 %d분 - %d번 고객(%d분 소요)이 %d번 ATM에 도착 VIP:%d\n", 9 + clock / 60, clock % 60, customer.id, customer.service_time, customer.ATM_num, customer.VIP);
		//손님이 VIP일 경우 줄 앞에 추가
		if (customer.VIP) {
			add_front(&ATM[customer.ATM_num], customer);
			ATM[customer.ATM_num].line++; //대기인원 증가
		}
		//VIP아닐 경우 줄 맨 뒤 추가
		else {
			enqueue(&ATM[customer.ATM_num], customer);
			ATM[customer.ATM_num].line++; //대기인원 증가
		}
		for (int i = 0; i < 3; i++) {
			if (!is_empty(&ATM[i])) { //ATM기기에 줄이 있으면
				if (ATM[i].front->service_time == 0) { //가장 앞 사람의 업무처리가 완료되었으면

					dequeue(&ATM[i]); //줄에서 뺀다
					total_customers = total_customers + 1; //업무처리 완료한 사람 수 증가
					if (!is_empty(&ATM[i])){
						printf("%d시 %d분 - %d번 고객(%d분 소요)이 %d번 ATM에서 서비스를 시작함\n", 9 + clock / 60, clock % 60, ATM[i].front->id, ATM[i].front->service_time, i);
						ATM[i].front->service_time = (ATM[i].front->service_time) - 1; //서비스 시작과 동시에 업무 처리 시간 감소
						total_wait = total_wait + (clock - ATM[i].front->arrival_time);
					}
				}
				else { //가장 앞 사람의 업무 처리 시간 감소
					ATM[i].front->service_time = (ATM[i].front->service_time) - 1;
				}
			}
		}
		if ((clock % 10 == 0) && clock != 0) { //시작 제외 10분마다 이탈
			for (int i = 0; i < 3; i++) {
				if (!is_empty(&ATM[i])) {
					QUEUENODE* pre = ATM[i].front;
					for (QUEUENODE* p = ATM[i].front->link; p != NULL;) {
						if (is_prime(p->id)) {
							total_wait = total_wait + (clock - p->arrival_time); //중간에 가는 사람 대기 시간을 총 대기 시간에 더함
							printf("%d번: 집에 갈래요!!\n", p->id);
							delete(&ATM[i], pre);
							p = pre->link;
							continue;
						}
						pre = p;
						p = p->link;
					}
				}
			}

		}
		for (int i = 0; i < 3; i++) {
			printf("ATM(%d): ", i); print_queue(&ATM[i]); //현재 ATM상태 프린트
		}
	}		
	printf("\n---------------업무 종료---------------\n");
	printf("총 %d명의 고객이 업무를 완료하였으며, 평균 %d분을 대기하였습니다. 10시 59분 현재 %d명이 기다리고 있습니다.\n",total_customers,total_wait/120 ,ATM[0].line+ATM[1].line+ATM[2].line-3);
	//업무를 보는 중인 사람은 완료한 고객의 수에 포함하지 않았음. 
	return 0;
}
