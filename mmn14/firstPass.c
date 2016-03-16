#include "header.h"



/*----------------------------------------------------------------------------*/
int firstPassManager(FILE *file){
    char lineHolder[MAX_LINE_LEN+1];
    Data data;
    data.lc=0;
    data.dc=0;
    data.ic=0;
    /* NULL means EOF. When we reach EOF it means we're done */
    while(fgets(lineHolder,MAX_LINE_LEN,file) != NULL ){
        data.line=lineHolder;
        data.lc++;
        if (lineValidator(&data,file) == 1){
            lineHandler(&data);
        }
    }
    return 0;
}



/*----------------------------------------------------------------------------*/
int lineValidator(Data * data,FILE *file){
    /* check if a line is longer than MAX_LINE_LEN */
    if(strlen(data->line)>=MAX_LINE_LEN-1 && (data->line)[MAX_LINE_LEN-1] != EOF && (data->line)[MAX_LINE_LEN-1] != '\n'){
        printf("ERROR line is longer than %d chars\n", MAX_LINE_LEN);
        /* get rid of the rest of the line so we don't get the rest of it with fgets instead of a new one */
        eatLine(file);
        printf("%s\n",data->line);
        return 0;
    }
    /* check if it's an empty line */
    eatSpace(data);
    if(*(data->line)=='\n' || *(data->line)==EOF){
        return 0;
    }
    /* if it's a comment line */
    if(*(data->line)==';'){
        return 0;
    }
    return 1;
}

/*----------------------------------------------------------------------------*/
int lineHandler(Data * data){
    char tag[30];
    getTag(data,tag);

    /* there's a tag at the start of the line */
    if (tag != NULL){
        /*printf("%s\n",tag);*/
        if (checkIfTagExist(tag) == 1){
        printf("[Error]: you have the tag %s more then once.\n",tag);
            return 0;
        }
        /* dagel hit's semel
         lines 3-4*/

    }
    if (isFakeInstruction(line)==1){
        /*if contain semel enter to table semel, value = DC
         lines 6-7*/
        return 0;
    }
    if (isExternOrEntry(line)==1){
        /*lines 9-10*/

        return 0;
    }
    if (existLabel(line) == 1){
            /*lines 11*/

    }
    /*lines 12 - 13*/
    return 0;

}

/*----------------------------------------------------------------------------*/
int tagCheck(char* tag){
    int index = 0;
    int static tagsArray[MAX_ASM_LINES];
    int static numOfTag = 0;

    for (index = 0; index< numOfTag;index++){
        if (strcmp(tagsArray[index],tag) == 0){
            return 1;
        }
    }
    tagsArray[numOfTag] = tag;
    numOfTag++;
    return 0;
}

/*----------------------------------------------------------------------------*/
void getTag(Data * data,char * tag){
    int counter=0;
    char * c = data->line+1;
    if (checkLetters(*(data->line))== 0){
        return NULL;
    }
    while(!isspace(*c) && (*c != ':')){
        if (checkLetterOrNumber(*c) == 0){
            return NULL;
        }
        counter++;
        c++;
    }
    if (*c == ':'){
        while(counter>=0){
            *tag=*(data->line);
            tag++;
            counter--;
        }
    }
    return;
}

/*----------------------------------------------------------------------------*/
int directiveHandler(char* line){
return 0;
}
/*----------------------------------------------------------------------------*/
int stringDirectiveHandler(char* line){
return 0;
}
/*----------------------------------------------------------------------------*/
int dataDirectiveHandler(char* line){
return 0;
}

/*----------------------------------------------------------------------------*/
int externHandler(char* line){
return 0;
}

/*----------------------------------------------------------------------------*/
int entryHandler(char* line){
return 0;
}

