/**
 * Matrix4
 *
 * Copyright (c) 2017 Mathew Mariani
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the MIT license. See LICENSE for details.
 */

#pragma once

class Matrix4 {
public:
	Matrix4();
	~Matrix4() = default;

	/**
	 * Use this function to get a pointer to the array elements.
	 */
	const float* getData() const;

	/**
	 * Use this function to reset the matrix to the identity matrix.
	 */
	void identity();

	/**
	 * Use this function to set this matrix to an array of elements.
	 */
	void set(float* matrix);

	/**
	 * Use this function to translate the matrix by (x, y, z).
	 */
	void translate(float x, float y, float z);

	/**
	 * Use this function to scale the matrix by (x, y, z).
	 */
	void scale(float x, float y, float z);

	/**
	 * Use this function to perform a basic rotation (in radians) about the x-axis.
	 */
	void rotateX(float radians);

	/**
	 * Use this function to perform a basic rotation (in radians) about the y-axis.
	 */
	void rotateY(float radians);

	/**
	 * Use this function to perform a basic rotation (in radians) about the z-axis.
	 */
	void rotateZ(float radians);

	/**
	 * Use this function to create an orthographic projection matrix.
	 */
	static Matrix4 ortho(float left, float right, float bottom, float top, float far, float near);

public:
	Matrix4 operator * (const Matrix4& m) const;

private:
	float data[16];
};	// matrix4
