#ifndef __CAMERA_H__
#define __CAMERA_H__


class Camera {
    public:
        Camera(void);
        ~Camera(void);
        void Init(void);
        void DeInit(void);
        void Open(long long t);
        void Close(int s);


    private:
        
};
#endif
