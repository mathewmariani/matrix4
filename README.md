# Matrix4

A small (4x4) Matrix object for use with OpenGL.

## Data Representation

OpenGL matrices are 16-value arrays with base vectors laid out contiguously in memory. The translation components occupy the 12th, 13th, and 14th elements of the 16-element matrix.

```
Matrix4 element layout
| 00 04 08 12 |
| 01 05 09 13 |
| 02 06 10 14 |
| 03 07 11 15 |

Matrix4 Identity
| 1.00 0.00 0.00 0.00 |
| 0.00 1.00 0.00 0.00 |
| 0.00 0.00 1.00 0.00 |
| 0.00 0.00 0.00 1.00 |

Matrix4 Translate (1, 2, 3)
| 1.00 0.00 0.00 1.00 |
| 0.00 1.00 0.00 2.00 |
| 0.00 0.00 1.00 3.00 |
| 0.00 0.00 0.00 1.00 |

Matrix4 Scale (1, 2, 3)
| 1.00 0.00 0.00 0.00 |
| 0.00 2.00 0.00 0.00 |
| 0.00 0.00 3.00 0.00 |
| 0.00 0.00 0.00 1.00 |

Matrix4 RotateX 25 radians
| 1.00  0.00 0.00 0.00 |
| 0.00  0.99 0.13 0.00 |
| 0.00 -0.13 0.99 0.00 |
| 0.00  0.00 0.00 1.00 |

Matrix4 RotateY 25 radians
| 0.99 0.00 -0.13 0.00 |
| 0.00 1.00  0.00 0.00 |
| 0.13 0.00  0.99 0.00 |
| 0.00 0.00  0.00 1.00 |
```

## Function Reference

### const float* getData() const
Use this function to get a pointer to the array elements.

### void identity();
Use this function to reset the matrix to the identity matrix.

### void set(float* matrix);
Use this function to set this matrix to an array of elements.

### void translate(float x, float y, float z);
Use this function to translate the matrix by (x, y, z).

### void scale(float x, float y, float z);
Use this function to scale the matrix by (x, y, z).

### void rotateX(float radians);
Use this function to perform a basic rotation (in radians) about the x-axis.

### void rotateY(float radians);
Use this function to perform a basic rotation (in radians) about the y-axis.

### void rotateZ(float radians);
Use this function to perform a basic rotation (in radians) about the z-axis.

### static Matrix4 ortho(float left, float right, float bottom, float top, float far, float near);
Use this function to create an orthographic projection matrix.
