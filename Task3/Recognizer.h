#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

int key_hue     =100;
int key_light   =100;
int key_sat     =100;

void recogniseStickersByThreshold(cv::Mat image,std::vector<cv::Mat> &stickers) {
 cv::Mat image_hsv;
 std::vector< std::vector<cv::Point> > contours;
 cv::cvtColor(image, image_hsv, cv::COLOR_BGR2HSV ); // Преобразуем в hsv
 cv::Mat tmp_img(image.size(),CV_8U);
 // Выделение подходящих по цвету областей. Цвет задается константой :)
 cv::inRange(image_hsv, cv::Scalar(key_light-2,key_sat-20,key_hue-35),
cv::Scalar(key_light+2,key_sat+20,key_hue+35), tmp_img);
 // "Замазать" огрехи в при выделении по цвету
 cv::dilate(tmp_img,tmp_img,cv::Mat(),cv::Point(-1,-1),3);
 cv::erode(tmp_img,tmp_img,cv::Mat(),cv::Point(-1,-1),1);
 //Выделение непрерывных областей
 cv::findContours(tmp_img,contours,CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
 for (uint i = 0; i<contours.size(); i++) { cv::Mat sticker;
 //Для каждой области определяем ограничивающий прямоугольник
 cv::Rect rect=cv::boundingRect(contours[i]);
 image(rect).copyTo(sticker);
 stickers.push_back(sticker); //Добавить к массиву распознанных стикеров
 }
}