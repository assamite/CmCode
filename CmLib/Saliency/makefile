OPENCV_LIBS = -L/opt/local/lib -lopencv_calib3d -lopencv_contrib -lopencv_core -lopencv_features2d -lopencv_flann -lopencv_gpu -lopencv_highgui -lopencv_imgproc -lopencv_legacy -lopencv_ml -lopencv_nonfree -lopencv_objdetect -lopencv_photo -lopencv_stitching -lopencv_superres -lopencv_ts -lopencv_video -lopencv_videostab 

test:
	g++ -std=c++11 -o test.o test.cpp CmSalCut.cpp CmSaliencyRC.cpp \
	../Segmentation/EfficientGraphBased/segment-image.cpp \
	../Basic/CmCv.cpp ../Basic/CmDefinition.cpp -I/usr/local/include \
	-I/opt/local/include $(OPENCV_LIBS)
	
shared_osx:
	g++ -dynamiclib -Wall -O2 -I/usr/include/python2.7/ -lpython2.7 \
	-std=c++11 -o saliency.dylib CmSalCut.cpp CmSaliencyRC.cpp \
	../Segmentation/EfficientGraphBased/segment-image.cpp \
	../Basic/CmCv.cpp ../Basic/CmDefinition.cpp -I/usr/local/include \
	-I/opt/local/include $(OPENCV_LIBS) 
	mv ./saliency.dylib ./saliency.so
	
shared_unix:
	g++ -shared -Wall -g -fPIC -I/usr/include -I/usr/lib -O2 \
	-std=c++11 -I/usr/include/python2.7/ -lpython2.7 \
	-o saliency.so CmSalCut.cpp CmSaliencyRC.cpp \
	../Segmentation/EfficientGraphBased/segment-image.cpp \
	../Basic/CmCv.cpp ../Basic/CmDefinition.cpp -I/usr/local/include \
	-I/opt/local/include $(OPENCV_LIBS) 