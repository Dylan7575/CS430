#include <stdlib.h>
#include <stdio.h>
void p6_to_p3(FILE*);
void p3_to_p6(FILE*);

int main() {
    FILE * fp ;
    fp= fopen("C:\\Users\\Dylan\\ClionProjects\\project1CS430\\boxes_1.ppm","r");
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
            p6_to_p3(fp);
            //if p6 sending it to function for converting to p3
        }
        else if (header[0]=='P'&&header[1]=='3'){
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
    int width,height,whitespace=3;
    int buf;
    fgetc(fp);
    whitespace--;
    printf("%c,%i",buf,whitespace);



    printf("%c",buf);



    //nothing yet
}
void p3_to_p6(FILE * fp){
    int width,height;
}