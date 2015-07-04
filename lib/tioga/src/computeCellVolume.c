
double computeCellVolume(double xv[8][3],int nvert)
{
 double vol;
 int itype;
 int nfaces;
 int numverts[4][6]={3,3,3,3,0,0,4,3,3,3,3,0,3,4,4,4,3,0,4,4,4,4,4,4};
 int faceInfo[4][24]={1,2,3,0,1,4,2,0,2,4,3,0,1,3,4,0,0,0,0,0,0,0,0,0,
                       1,2,3,4,1,5,2,0,2,5,3,0,4,3,5,0,1,4,5,0,0,0,0,0,
                       1,2,3,0,1,4,5,2,2,5,6,3,1,3,6,4,4,6,5,0,0,0,0,0,
                       1,2,3,4,1,5,6,2,2,6,7,3,3,7,8,4,1,4,8,5,5,8,7,6};
 
 switch(nvert)
   {
   case 4:
     itype=0;
     nfaces=4;
     break;
   case 5:
     itype=1;
     nfaces=5;
     break;
   case 6:
     itype=2;
     nfaces=5;
     break;
   case 8:
     itype=3;
     nfaces=6;
     break;
   }
     
 vol=cellVolume_(xv,&numverts[itype],&faceInfo[itype],&nfaces,&nvert);
 return vol;
}