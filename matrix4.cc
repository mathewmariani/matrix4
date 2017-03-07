/**
 * Matrix4
 *
 * Copyright (c) 2017 Mathew Mariani
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the MIT license. See LICENSE for details.
 */

// C/C++
#include <cstring>
#include <math.h>

#include "matrix4.h"

Matrix4::Matrix4() {
	identity();
}

Matrix4 Matrix4::operator * (const Matrix4& m) const {
	Matrix4 ret;

	ret.data[0] = ((data[0]*m.data[0])+(data[1]*m.data[4])+(data[2]*m.data[8])+(data[3]*m.data[12]));
	ret.data[1] = ((data[0]*m.data[1])+(data[1]*m.data[5])+(data[2]*m.data[9])+(data[3]*m.data[13]));
	ret.data[2] = ((data[0]*m.data[2])+(data[1]*m.data[6])+(data[2]*m.data[10])+(data[3]*m.data[14]));
	ret.data[3] = ((data[0]*m.data[3])+(data[1]*m.data[7])+(data[2]*m.data[11])+(data[3]*m.data[15]));

	ret.data[4] = ((data[4]*m.data[0])+(data[5]*m.data[4])+(data[6]*m.data[8])+(data[7]*m.data[12]));
	ret.data[5] = ((data[4]*m.data[1])+(data[5]*m.data[5])+(data[6]*m.data[9])+(data[7]*m.data[13]));
	ret.data[6] = ((data[4]*m.data[2])+(data[5]*m.data[6])+(data[6]*m.data[10])+(data[7]*m.data[14]));
	ret.data[7] = ((data[4]*m.data[3])+(data[5]*m.data[7])+(data[6]*m.data[11])+(data[7]*m.data[15]));

	ret.data[8] = ((data[8]*m.data[0])+(data[9]*m.data[4])+(data[10]*m.data[8])+(data[11]*m.data[12]));
	ret.data[9] = ((data[8]*m.data[1])+(data[9]*m.data[5])+(data[10]*m.data[9])+(data[11]*m.data[13]));
	ret.data[10] = ((data[8]*m.data[2])+(data[9]*m.data[6])+(data[10]*m.data[10])+(data[11]*m.data[14]));
	ret.data[11] = ((data[8]*m.data[3])+(data[9]*m.data[7])+(data[10]*m.data[11])+(data[11]*m.data[15]));

	ret.data[12] = ((data[12]*m.data[0])+(data[13]*m.data[4])+(data[14]*m.data[8])+(data[15]*m.data[12]));
	ret.data[13] = ((data[12]*m.data[1])+(data[13]*m.data[5])+(data[14]*m.data[9])+(data[15]*m.data[13]));
	ret.data[14] = ((data[12]*m.data[2])+(data[13]*m.data[6])+(data[14]*m.data[10])+(data[15]*m.data[14]));
	ret.data[15] = ((data[12]*m.data[3])+(data[13]*m.data[7])+(data[14]*m.data[11])+(data[15]*m.data[15]));

	return ret;
}

const float* Matrix4::getData() const {
	return data;
}

void Matrix4::identity() {

	/**
	 * | 1       |
	 * |   1     |
	 * |     1   |
	 * |       1 |
	 */

	memset(data, 0, sizeof(float) * 16);
	data[0] = 1.0f;
	data[5] = 1.0f;
	data[10] = 1.0f;
	data[15] = 1.0f;
}

void Matrix4::set(float* matrix) {
	memcpy(&data, matrix, sizeof(data));
}

void Matrix4::translate(float x, float y, float z) {
	/**
	 * Matrix Translation
	 * | 1       |
	 * |   1     |
	 * |     1   |
	 * | x y z 1 |
	 */

	Matrix4 t;
	t.set(data);

	identity();
	data[12] = x;
	data[13] = y;
	data[14] = z;

	(*this) = (*this) * t;
}

void Matrix4::scale(float sx, float sy, float sz) {
	/**
	 * Matrix Translation
	 * | sx      |
	 * |   sy    |
	 * |     sz  |
	 * |       1 |
	 */

	Matrix4 t;
	t.set(data);

	identity();
	data[0] = sx;
	data[5] = sy;
	data[10] = sz;

	(*this) = (*this) * t;
}

void Matrix4::rotateX(float radians) {
	/**
	 * Matrix Rotation X
	 * | 1       |
	 * |   c s   |
	 * |  -s c   |
	 * |       1 |
	 */

	float c = cosf (radians);
	float s = sinf (radians);

	Matrix4 t;
	t.set(data);

	identity();
	data[5] = c;
	data[6] = s;
	data[9] = -s;
	data[10] = c;

	(*this) = (*this) * t;
}

void Matrix4::rotateY(float radians) {
	/**
	 * Matrix Rotation X
	 * | c  -s   |
	 * |   1     |
	 * | s   c   |
	 * |       1 |
	 */

	float c = cosf (radians);
	float s = sinf (radians);

	Matrix4 t;
	t.set(data);

	identity();
	data[0] = c;
	data[2] = -s;
	data[8] = s;
	data[10] = c;

	(*this) = (*this) * t;
}

void Matrix4::rotateZ(float radians) {
	/**
	 * Matrix Rotation X
	 * | c s     |
	 * |-s c     |
	 * |         |
	 * |       1 |
	 */

	float c = cosf (radians);
	float s = sinf (radians);

	Matrix4 t;
	t.set(data);

	identity();
	data[0] = c;
	data[1] = s;
	data[4] = -s;
	data[5] = c;

	(*this) = (*this) * t;
}

Matrix4 Matrix4::ortho(float left, float right, float bottom, float top, float far, float near) {
	Matrix4 m;

	m.data[0] = (2.0f / (right - left));
	m.data[5] = (2.0f / (top - bottom));
	m.data[10] = (-1.0);

	m.data[12] = (-(right + left) / (right - left));
	m.data[13] = (-(top + bottom) / (top - bottom));
	m.data[14] = (-(far + near) / (far - near));
	return m;
}
