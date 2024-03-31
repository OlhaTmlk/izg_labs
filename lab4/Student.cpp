#include "Student.h"

#include <osg/Plane>
#include <iostream>

#define _USE_MATH_DEFINES
#include <math.h>
#include <algorithm>

osg::Matrix inverse(const osg::Matrix& m)
{
    return osg::Matrix::inverse(m);
}

double degreesToRadians(double angleInDegrees)
{
    return osg::DegreesToRadians(angleInDegrees);
}

osg::Matrix getScaleMatrix(const osg::Vec3d& scale)
{
    //Task 1 - fill in the scale matrix

    osg::Matrix m 
            (scale.x(), 0, 0, 0,
            0, scale.y(), 0, 0,
            0, 0, scale.z(), 0,
            0, 0, 0, 1);

    return m;
}

osg::Matrix getTranslationMatrix(const osg::Vec3d& translation)
{
    //Task 2 - fill in the translation matrix

    osg::Matrix m
       (1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        translation.x(), translation.y(), translation.z(), 1);

    return m;
}

osg::Matrix rotateAroundX(double angle)
{

    double sina = std::sin(angle);
    double cosa = std::cos(angle);

    //Task 3 - fill in the rotation matrix around X axis
    osg::Matrix m
        (1, 0, 0, 0,
        0, cosa, sina, 0,
        0, -sina, cosa, 0,
        0, 0, 0, 1);

    return m;
}

osg::Matrix rotateAroundY(double angle)
{
    double sina = std::sin(angle);
    double cosa = std::cos(angle);

    //Task 4 - fill in the rotation matrix around Y axis
    osg::Matrix m
        (cosa, 0, -sina, 0,
        0, 1, 0, 0,
        sina, 0, cosa, 0,
        0, 0, 0, 1);

    return m;
}

osg::Matrix rotateAroundZ(double angle)
{
    double sina = std::sin(angle);
    double cosa = std::cos(angle);

    //Task 5 - fill in the rotation matrix around Z axis
    osg::Matrix m
        (cosa, sina, 0, 0,
        -sina, cosa, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1);

    return m;
}

osg::Matrix getForwardTransformation()
{
    //Task 6 - fill in forward transformation matrix consisting of 3 individual transformation matrices
    osg::Vec3d tr(-2.0, 0.0, 2.0);
    osg::Matrix transl = getTranslationMatrix(tr);

    osg::Vec3d sc(2.0, 2.0, 2.0);
    osg::Matrix scale = getScaleMatrix(sc);

    double angleZ = degreesToRadians(225.0);
    osg::Matrix rotate = rotateAroundZ(angleZ);

    osg::Matrix m = transl * scale * rotate ;

    return m;
}
osg::Matrix getBackwardTransformation()
{
    //Task 7 - fill in backward transformation matrix consisting of 3 individual transformation matrices (you can use inverse if it helps you).
    osg::Vec3d tr(-2.0, 0.0, 2.0);
    osg::Matrix transl = getTranslationMatrix(tr);

    osg::Vec3d sc(2.0, 2.0, 2.0);
    osg::Matrix scale = getScaleMatrix(sc);

    double angleX = degreesToRadians(-135.0);
    osg::Matrix rotate = rotateAroundX(angleX);


    osg::Matrix m = rotate * transl * scale ;
    return m;
}
