#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void p6_to_p3(FILE*);
void p3_to_p6(FILE*);
void parse_white_space(FILE*);

int main() {
    FILE * fp ;
    fp= fopen("/Users/Hayden/Downloads/CS430-master/smile.ppm","r");
    //opening file
    if (fp==NULL){
        perror("That file does not exist");
        exit(-1);
        //error checking file opening
    }
    else{
        size_t result;
        int header_size=2;
        char header[header_size];
        //creating buffer for checking what format the file is in
        result=fread(header,1,header_size,fp);

        //reading in file format
        if(result!=header_size){
            perror("Could not read your file");
            //error checking file reading
        }
        if(header[0]=='P'&&header[1]=='6'){
            // printf("req");
            p6_to_p3(fp);
            //if p6 sending it to function for converting to p3
        }
        else if (header[0]=='P'&&header[1]=='3'){
            //printf("req");
            p3_to_p6(fp);
            //if p3 sending it to function for converting to p6
        }
        else{
            perror("Your file is not a PPM file");
            //if it is not a PPM file giving user an error message
        }




    }

    fclose(fp);

    return 0;
}

void p6_to_p3(FILE * fp){
    int width,height,temp,max,i=0;
    char temp2;
    parse_white_space(fp);

    do temp=fgetc(fp);while(temp!='\n');
    fscanf(fp,"%i ",&height);
    fscanf(fp,"%i ",&width);
    fscanf(fp,"%i ",&max);
    //printf("%i",height*width);
    int f =ftell(fp);
    fseek(fp,-f,SEEK_CUR);
    int header[f];
    fread(header, 1, f,fp);
    //printf("%c",*header);
    FILE* output=fopen("/Users/Hayden/ClionProjects/cs430_project1/output.ppm","w+");
    fwrite(header,1, f,output);
    fclose(fp);



    //int temp = fgetc(fp);
    //printf("%c",temp);






    //nothing yet
}

void p3_to_p6(FILE * fp){
    int width,height,temp,max,i=0;
    char temp2;
    parse_white_space(fp);

    do temp=fgetc(fp);while(temp!='\n');
    //int* temp2=get_num(fp);
    fscanf(fp,"%i ",&height);
    fscanf(fp,"%i ",&width);
    fscanf(fp,"%i ",&max);
    printf("%i",height);
    int* buffer=malloc(height*width);


    int f =ftell(fp);
    fseek(fp,-f,SEEK_CUR);
    int header[f];
    fread(header, 1, f,fp);
    //printf("%c",*header);
    FILE* output=fopen("/Users/Hayden/ClionProjects/cs430_project1/output.ppm","wb+");
    fprintf(fp,header);
    fclose(output);
    int temp4;
    while((temp4=getc(fp))!=EOF){

        *buffer=temp4;
        buffer++;

   }
    *buffer=atoi(buffer);
    fwrite(buffer,1,height*width,output);

    //fgets(buffer,(height*width)-f,fp);
    //fread(buffer,1,width*height,fp);
    //atoi(buffer);
    // fwrite(buffer,1,width*height,output);


/*
    do{
        temp2=fgetc(fp);
        buffer[i++]=temp2;

    } while(temp2!=' ');
    fwrite(buffer,1,width*height,output);
    */












    //


    //fseek(fp,0,SEEK_END);
    //   int a = ftell(fp);
    //  printf("%i",a);
    // fsetpos(fp,f);
    // fread(buffer,1,a-f,fp);
    // fwrite(buffer,1,a-f,output);




    //fseek(output,1,SEEK_SET);
    //fwrite("6",1,1,output);


    // *buffer=fgetc(fp);
    //temp2 =fgetc(fp);
    //   printf("%c %i",header[2], f);










}
void parse_white_space(FILE *fp){
    while (fgetc(fp)==' '){
        fseek(fp,1,SEEK_CUR);
    }
}

