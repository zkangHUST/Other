#include<stdio.h>
#include "cJSON.h"
int main()
{
	cJSON * pJsonRoot = NULL;
	pJsonRoot = cJSON_CreateObject();
	cJSON_AddStringToObject(pJsonRoot, "hello", "hello world");
	cJSON_AddNumberToObject(pJsonRoot, "number", 10010);
	cJSON_AddBoolToObject(pJsonRoot, "bool", 1);
	cJSON * pSubJson = NULL;
    pSubJson = cJSON_CreateObject();
    if(NULL == pSubJson)
    {
          // create object faild, exit
          cJSON_Delete(pJsonRoot);
          return NULL;
    }
    cJSON_AddStringToObject(pSubJson, "subjsonobj", "a sub json string");
    cJSON_AddItemToObject(pJsonRoot, "subobj", pSubJson);
	char * p = cJSON_Print(pJsonRoot);
	printf("%s\n",p);
	cJSON* type = cJSON_GetObjectItem(pJsonRoot, "bool");
	p = cJSON_Print(type);
	printf("%s\n",p);
	printf("type = %d\n",type->type);
	return 0;
}
