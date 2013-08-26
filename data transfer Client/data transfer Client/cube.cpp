
#include "app.h"
#include "cube.h"
#include "math.h"

void CCube::Render()
{
	glPushMatrix();

	glTranslatef(Center.x, Center.y, Center.z);
	glRotatef(angleRotY * 180.0f / Pi, 0.0f, 1.0f, 0.0f);

 	glBegin(GL_QUADS);
	// Передняя грань
	glNormal3f( 0.0f,  0.0f,  fLen);
	glColor3f(1.0, 0.0, 0.0); glVertex3f(-fLen, -fLen,  fLen);
	glColor3f(1.0, 0.0, 0.0); glVertex3f(-fLen,  fLen,  fLen);
	glColor3f(1.0, 0.0, 0.0); glVertex3f( fLen,  fLen,  fLen);
	glColor3f(1.0, 0.0, 0.0); glVertex3f( fLen, -fLen,  fLen);
	// Задняя грань
	glNormal3f( 0.0f,  0.0f, -fLen);
	glColor3f(1.0, 0.0, 0.0); glVertex3f(-fLen, -fLen, -fLen);
	glColor3f(1.0, 0.0, 0.0); glVertex3f(-fLen,  fLen, -fLen);
	glColor3f(1.0, 0.0, 0.0); glVertex3f( fLen,  fLen, -fLen);
	glColor3f(1.0, 0.0, 0.0); glVertex3f( fLen, -fLen, -fLen);
	// Верхняя грань
	glNormal3f( 0.0f,  fLen,  0.0f);
	glColor3f(0.0, 0.0, 1.0); glVertex3f(-fLen,  fLen, -fLen);
	glColor3f(0.0, 0.0, 1.0); glVertex3f(-fLen,  fLen,  fLen);
	glColor3f(0.0, 0.0, 1.0); glVertex3f( fLen,  fLen,  fLen);
	glColor3f(0.0, 0.0, 1.0); glVertex3f( fLen,  fLen, -fLen);
	// Нижняя грань
	glNormal3f( 0.0f, -fLen,  0.0f);
	glColor3f(0.0, 0.0, 1.0); glVertex3f(-fLen, -fLen, -fLen);
	glColor3f(0.0, 0.0, 1.0); glVertex3f( fLen, -fLen, -fLen);
	glColor3f(0.0, 0.0, 1.0); glVertex3f( fLen, -fLen,  fLen);
	glColor3f(0.0, 0.0, 1.0); glVertex3f(-fLen, -fLen,  fLen);
	// Правая грань
	glNormal3f( fLen,  0.0f,  0.0f);
	glColor3f(0.0, 1.0, 0.0); glVertex3f( fLen, -fLen, -fLen);
	glColor3f(0.0, 1.0, 0.0); glVertex3f( fLen,  fLen, -fLen);
	glColor3f(0.0, 1.0, 0.0); glVertex3f( fLen,  fLen,  fLen);
	glColor3f(0.0, 1.0, 0.0); glVertex3f( fLen, -fLen,  fLen);
	// Левая грань
	glNormal3f(-fLen,  0.0f,  0.0f);
	glColor3f(0.0, 1.0, 0.0); glVertex3f(-fLen, -fLen, -fLen);
	glColor3f(0.0, 1.0, 0.0); glVertex3f(-fLen, -fLen,  fLen);
	glColor3f(0.0, 1.0, 0.0); glVertex3f(-fLen,  fLen,  fLen);
	glColor3f(0.0, 1.0, 0.0); glVertex3f(-fLen,  fLen, -fLen);

	glEnd();

	glPopMatrix();
}