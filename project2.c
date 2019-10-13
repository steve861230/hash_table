#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define len 1024

int num_dict=0;

typedef struct dictionary{
	int count;
	int key;
	char word[len];
	struct dictionary* next;
}dict;

int hash_key(char *temp){
	int key=0;
	int len_word;
	len_word=strlen(temp);
	for(int i=0;i<len_word;i++){
	
		key=key+temp[i]*7;		
	}
	key=key%2048;
	
	return key;	
} 


int main(int argc, char **argv){
	
	int index;
	char temp[len];
	FILE *fp_in,*fp_in1, *fp_out;    
    char *file_1, *file_2;
    file_1 = argv[1];
    file_2 = argv[2];
    fp_in = fopen(argv[1], "r");    
	char str[len];
    dict* hash_table[2048]  ; 
	for (int i = 0; i < 2048; ++i){
            hash_table[i]=NULL;
            
 		}
	
	int k=0;
	
	char input[len];
	char arr[len];
	while(fgets(arr,100,fp_in)!=NULL){
		int s=0;
			for(int d=0;d<len;d++){
		
			input[d]='\0';
			}
		while(1){

			char ch;
			ch=fgetc(fp_in);
			if(!(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9')||(ch=='_'))
			break;
			if(ch==10)
			break;
			
			if(ch>='A'&&ch<='Z'){
			ch=ch+32;
			input[s]=ch;
			}
			else{
			input[s]=ch;
			}
			s++;
		}
		strcpy(str,input);
		k=hash_key(str);
		dict *bucket=(dict *)malloc(sizeof(dict));
		
		if(hash_table[k]==NULL){
			strcpy(bucket->word,str);	
			bucket->key=k;		
			bucket->next=NULL;
			bucket->count=0;
			hash_table[k]=bucket;
		}
	
		else{
			
			dict* slot = (dict*)malloc(sizeof(dict));
			dict* ptr = hash_table[k]; 
			
			strcpy(slot->word,str);
			
			slot->key=k;
			slot->next=NULL;
			slot->count=0;
			if(ptr==NULL)
                ptr=slot;
			else{
			while(ptr->next!=NULL){
            	ptr=ptr->next;
			}
			ptr->next=slot;
			}
		}
}
   
    
    fclose(fp_in);
    fp_in1 = fopen(file_2, "r"); 
 
    char temp2 [len];
	int x;
	while(fscanf(fp_in,"%s",temp2)!=EOF){
		x=hash_key(temp2);
		    
		if(temp2!=""){
			
			dict* ptr2= hash_table[x];
            while(ptr2!=NULL){
                
				if(strcmp(ptr2->word,temp2)==0){
                    ptr2->count++;
                    break;
                }
                
				else{
					if(ptr2->next== NULL)
						break;
                    ptr2=ptr2->next;
            	}
			}
		}
	}
	fclose(fp_in1);
	fp_out = fopen("output.txt","w+t");
	fp_in = fopen(argv[1], "r"); 
	while(fgets(arr,100,fp_in)!=NULL){
		int s=0;
			for(int d=0;d<len;d++){
		
			temp[d]='\0';
			}
			while(1){
			char ch;
			ch=fgetc(fp_in);
			if(!(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9')||(ch=='_'))
				break;
			if(ch==10)
			break;
			
			if(ch>='A'&&ch<='Z'){
			ch=ch+32;
			temp[s]=ch;
			}
			else{
			temp[s]=ch;
			}
			s++;
		}
	index=hash_key(temp);
		
		dict* ptr3 = hash_table[index];
		while(1){
		
		if(strcmp(ptr3->word,temp)==0){
			fprintf(fp_out, "%d\n", ptr3->count);
			break;
		}
		else{
			ptr3=ptr3->next;
		
			}
		
		}
	}
	fclose(fp_in);
	fclose(fp_out);
	
	return 0;
}

