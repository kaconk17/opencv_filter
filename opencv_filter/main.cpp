//
//  main.cpp
//  opencv_filter
//
//  Created by Hartono on 19/12/19.
//  Copyright © 2019 Hartono. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;


void lowpass(Mat gambar){
    Mat img2;
    int a;
    Scalar intensity1 = 0;
    img2 = gambar.clone();
    
    cout << "Masukkan ukuran mask [1 - 10] :\n";
    cin >> a;
    
    for (int i =0; i< gambar.rows-a; i++) {
        for (int j = 0; j< gambar.cols -a; j++) {
            Scalar intensity2;
            for (int p = 0; p<a; p ++) {
                for (int q =0 ; q<a; q++) {
                    intensity1 = gambar.at<uchar>(i+p, j+q);
                    intensity2.val[0] += intensity1.val[0];
                }
            }
            
            img2.at<uchar>(i+(a-1)/2, j+(a-1)/2)=intensity2.val[0]/(a*a);
        }
    }
   
    
    
    imshow("Gambar original", gambar);
    imshow("Gambar Lowpass filter ", img2);
    waitKey(0);
    destroyAllWindows();
   
}

void highpass(Mat gambar){
    Mat img2;
       int a;
       Scalar intensity1 = 0;
      
       //cvtColor(gambar, gambar, COLOR_BGR2GRAY);
        img2 = gambar.clone();
    
       cout << "Masukkan ukuran mask [1 - 10] :\n";
       cin >> a;
       
       for (int i =0; i< gambar.rows-a; i++) {
           for (int j = 0; j< gambar.cols -a; j++) {
               Scalar intensity2=0;
               for (int p = 0; p<a; p ++) {
                   for (int q =0 ; q<a; q++) {
                       intensity1 = gambar.at<uchar>(i+p, j+q);
                       if ((p == (a-1)/2) && (q == (a-1)/2)) {
                           
                           intensity2.val[0] += (a*a-1) * intensity1.val[0];
                       }
                       else{
                            intensity2.val[0] += (-1) * intensity1.val[0];
                       }
                      
                   }
               }
               
               img2.at<uchar>(i+(a-1)/2, j+(a-1)/2)=intensity2.val[0]/(a*a);
           }
       }
      
       
       
       imshow("Gambar original", gambar);
       imshow("Gambar Highpass filter ", img2);
       waitKey(0);
       destroyAllWindows();
      
}

int main(int argc, const char * argv[]) {
      int pilih;
       Mat img;
      string path;
      cout << "=============Program image processing================\n";
      cout << "Pilih salah satu menu : \n";
      cout << "1. Operasi Lowpass filter gambar\n";
      cout << "2. Operasi Highpass filter gambar\n";
     
      
      cin >> pilih;
      
      switch (pilih) {
          case 1:
               cout << "Drag gambar kesini :\n";
                     cin >> path;
                    
                     img = imread(path,0);
                     if (img.empty()){
                         cout << "Error gambar tidak ditemukan !\n";
                         return -1;
                     }
                     lowpass(img);
              break;
          case 2:
                  cout << "Drag gambar kesini :\n";
                  cin >> path;
                 
                  img = imread(path,0);
                  if (img.empty()){
                      cout << "Error gambar tidak ditemukan !\n";
                      return -1;
                  }
                 highpass(img);
              break;
              
          default:
              cout << "Gambar tidak ditemukan";
      }
    return 0;
}
