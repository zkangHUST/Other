#include<stdio.h>
#include "cJSON.h"
int main()
{
	char *p="{\"stu\":[{\"name\":\"xiaoming\",\"ID\":20180723,\"score\":{\"math\":80,\"English\":92.5,\"Chinese\":90}},{\"name\":\"xiaohong\",\"ID\":20180724,\"score\":{\"math\":70,\"English\":80,\"Chinese\":95}}]}";
	
	int size,i;
	cJSON *temp,*name,*id,*stu, *temp1,*score,*chinese;

	temp=cJSON_Parse(p);
	char* c=cJSON_Print(temp);
	//printf("%s\n",c);	
	stu = cJSON_GetObjectItem(temp,"stu");
	if(stu && stu->type==cJSON_Array){
		size = cJSON_GetArraySize(stu);
		for(i=0;i<size;i++){
			temp1 = cJSON_GetArrayItem(stu,i);
			name= cJSON_GetObjectItem(temp1,"name");
			id = cJSON_GetObjectItem(temp1,"ID");
			score=cJSON_GetObjectItem(temp1,"score");
			if(score && score->type==cJSON_Object)
				chinese = cJSON_GetObjectItem(score,"chinese");
			if(name && name->type == cJSON_String)
				printf("%s\t",name->valuestring);
			if(id && id->type == cJSON_Number)
				printf("%d\t",id->valueint);
			if(chinese && chinese->type == cJSON_Number)
				printf("%d\n",chinese->valueint);
		}
	}
	cJSON_Delete(temp);
	return 0;
}

