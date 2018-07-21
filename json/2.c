#include<stdio.h>
#include "cJSON.h"
int main()
{
	char *p="{\"name\":\"xiaoming\",\"ID\":20180723,\"score\":{\"math\":80,\"English\":92.5,\"Chinese\":90}}";
	
	cJSON *temp,*name,*id ;
	temp=cJSON_Parse(p);
	char* c=cJSON_Print(temp);
	name = cJSON_GetObjectItem(temp,"name");
	id = cJSON_GetObjectItem(temp,"ID");
	if(name && name->type==cJSON_String)
		printf("%s\t",name->valuestring);	
	if(id && id->type==cJSON_Number)
		printf("%d\n",id->valueint);
	
	
	//printf("%s\n",c);
	cJSON_Delete(temp);
	return 0;
}

