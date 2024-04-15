#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <string>

using namespace std;
using namespace cv;

int main()
{
    string way = "photo_2022-08-03_19-27-25.jpg";

    Mat img_show = imread(way, 1);

    if (img_show.empty()) {
        cout << "nothing!" << endl;
        return 0;
    }
    else {
        cout << "norm" << endl;
    }

    putText(img_show, to_string(img_show.rows), Point(30, 30), FONT_HERSHEY_DUPLEX, 1.0, CV_RGB(0, 0, 0), 2);
    putText(img_show, to_string(img_show.cols), Point(100, 100), FONT_HERSHEY_DUPLEX, 1.0, CV_RGB(255, 255, 0), 2);

    circle(img_show, Point(300, 100), 50, Scalar(0, 255, 0), -1);
    rectangle(img_show, Point(600, 550), Point(550, 600), Scalar(0, 255, 0), 10);
    rectangle(img_show, Point(200, 230), Point(250, 300), Scalar(255, 0, 0), FILLED);
    line(img_show, Point(300, 270), Point(270, 300), Scalar(0, 0, 255), 5);

    int rows = img_show.rows;
    int cols = img_show.cols;

    Mat img_1 = img_show(Rect(0, 0, cols / 2, rows / 2));
    Mat img_2 = img_show(Rect(cols / 2, 0, cols / 2, rows / 2));
    Mat img_3 = img_show(Rect(0, rows / 2, cols / 2, rows / 2));
    Mat img_4 = img_show(Rect(cols / 2, rows / 2, cols / 2, rows / 2));

    imshow("1", img_1);
    imshow("2", img_2);
    imshow("3", img_3);
    imshow("4", img_4);
    
    Mat mask = Mat::zeros(img_show.size(), img_show.type());
    circle(mask, Point(mask.cols / 2, mask.rows / 2), 150, Scalar(255, 255, 255), -1, 8, 0);
    Mat r = Mat::zeros(img_show.size(), img_show.type());
    bitwise_and(img_show, mask, r);

    imshow("mask", r);

    waitKey(0);

    return 0;
}

