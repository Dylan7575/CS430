#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void p6_to_p3(FILE*);
void p3_to_p6(FILE*);
void parse_white_space(FILE*);
int get_number(FILE* fp);

typedef struct Pixel {
    unsigned char r, g, b;
} Pixel;

int main() {
    FILE * fp ;
    fp= fopen("C:\\Users\\Dylan\\ClionProjects\\project1CS430\\smile.ppm","r");
    //opening file
    if (fp==NULL){
        fprintf(stderr,"That file does not exist");
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
           //printf("req");
            p6_to_p3(fp);
            //if p6 sending it to function for converting to p3
        }
        else if (header[0]=='P'&&header[1]=='3'){
            //printf("req");
            p3_to_p6(fp);
            //if p3 sending it to function for converting to p6
        }
        else{
            fprintf(stderr,"This is not a ppm File");
            //if it is not a PPM file giving user an error message
        }




    }

    fclose(fp);

    return 0;
}

void p6_to_p3(FILE * fp){
    int width,height,temp,max,temp2,i=0;


    if(fgetc(fp)=='#') {
        do temp = fgetc(fp); while (temp != '\n');
    }

    fscanf(fp,"%i ",&height);
    fscanf(fp,"%i ",&width);
    fscanf(fp,"%i ",&max);
    if(max>255){
        fprintf(stderr,"This converter does no accept a max val of more than 255");
    }

    int buffer_size =width*height* sizeof(int);
    //printf("%i",width*height* sizeof(int));


    unsigned char buffer[width*height* sizeof(int)];
    int f =ftell(fp);
    fseek(fp,-f,SEEK_CUR);


    //printf("%c",*header);
    FILE* output=fopen("C:\\Users\\Dylan\\ClionProjects\\project1CS430\\output.ppm","w+");
    int header[f];
    fread(header, 1, f,fp);

    fwrite(header,1, f,output);


    //printf("%i",buffer_size);
    fread(buffer,1,buffer_size,fp);
    fwrite(buffer,1,buffer_size,output);
    //fprintf(output,"%c",buffer[0]);
    fclose(output);



}

void p3_to_p6(FILE * fp){

    int width,height,temp,max,temp2,i=0;
    parse_white_space(fp);

    if(fgetc(fp)=='#') {
        do temp = fgetc(fp); while (temp != '\n');
    }
    //int* temp2=get_num(fp);
    fscanf(fp,"%i ",&height);
    fscanf(fp,"%i ",&width);
    fscanf(fp,"%i ",&max);
    if(max>255){
        fprintf(stderr,"This converter does no accept a max val of more than 255");
    }
    Pixel pix[height*width];

    //printf("%i",max);
    char buffer[width*height];
    int buffer2[width*height];


    int f =ftell(fp);
    fseek(fp,-f,SEEK_CUR);
    int header[f];
    fread(header, 1, f,fp);
    //printf("%c",*header);
    FILE* output=fopen("C:\\Users\\Dylan\\ClionProjects\\project1CS430\\output.ppm","w+");
    fwrite(header,1, f,output);

    //int u =0;
    //pix.r=fgetc(fp);
    //buffer[0]=pix.r;
    //atoi(buffer);
   //fwrite(buffer,1,1,output);

    while((temp=fgetc(fp))!=EOF){
        fseek(fp,-1,SEEK_CUR);
        buffer[i]=temp;
        /*pix[i].r=get_number(fp);
        parse_white_space(fp);
        pix[i].g=get_number(fp);
        parse_white_space(fp);
        pix[i].b=get_number(fp);
        parse_white_space(fp);
         */
        i++;
    }
    buffer2[0] = atoi(buffer);
    printf("%i",pix[2].r);
    buffer[0]=pix[0].r;
    fwrite(buffer2,1,1,output);

    //get_number(fp);


    //fwrite(buffer,1,height*width,output);
    fclose(output);

}
int get_number(FILE* fp){
    int number;
    fscanf(fp,"%i",&number);
    return number;
}
void parse_white_space(FILE *fp){
    while (fgetc(fp)==' '){
        fseek(fp,1,SEEK_CUR);
    }
}

