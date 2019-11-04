#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <iostream>
#include <conio.h>
#include <string>

//#pragma comment (lib, "OpenGL32.lib")

#define WINDOW_TITLE "OpenGL Window"

float r = 1, g = 0, b = 0;
float points[4][2] = {
	{ -0.1f, 0.05f },{ 0.1f, 0.05f },{ 0.1f, -0.05f },{ -0.1f, -0.05f }
};

int page = 0;

LRESULT WINAPI WindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_CHAR:
		break;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		case VK_LEFT:
			page--;
			break;
		case VK_RIGHT:
			page++;
			break;
		}
		break;

	default:
		break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}
//--------------------------------------------------------------------

bool initPixelFormat(HDC hdc)
{
	PIXELFORMATDESCRIPTOR pfd;
	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));

	pfd.cAlphaBits = 8;
	pfd.cColorBits = 32;
	pfd.cDepthBits = 24;
	pfd.cStencilBits = 0;

	pfd.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;

	pfd.iLayerType = PFD_MAIN_PLANE;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;

	// choose pixel format returns the number most similar pixel format available
	int n = ChoosePixelFormat(hdc, &pfd);

	// set pixel format returns whether it sucessfully set the pixel format
	if (SetPixelFormat(hdc, n, &pfd))
	{
		return true;
	}
	else
	{
		return false;
	}
}
//--------------------------------------------------------------------

void DrawCircle(float cx, float cy, float r, int num_segments) {
	glBegin(GL_POLYGON);
	for (int ii = 0; ii < num_segments; ii++) {
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle 
		float x = r * cosf(theta);//calculate the x component 
		float y = r * sinf(theta);//calculate the y component 
		glVertex2f(x + cx, y + cy);//output vertex 
	}
	glEnd();
}

void drawCircle(float radius)
{
	float x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	float angle = 0;
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x1, y1);

	for (angle = 0; angle <= 360.0; angle += 0.2) {
		x2 = x1 + cos(angle)*radius;
		y2 = y1 + sin(angle)*radius;
		glVertex2f(x2, y2);
	}

	glEnd();
}

void drawFlag(int num)
{
	if (num == -1)
	{
		page = 5;
	}
	if (num == 6)
	{
		page = 0;
	}
	num = 2;

	switch (num)
	{
	case 0:
		// Pahang
		glBegin(GL_QUADS);
		{
			glColor3ub(255, 255, 255);

			glVertex2f(-0.9f, 0.9f);
			glVertex2f(0.9f, 0.9f);
			glVertex2f(0.9f, 0);
			glVertex2f(-0.9f, 0);
		}
		glEnd();

		glBegin(GL_QUADS);
		{
			glColor3ub(0, 0, 0);

			glVertex2f(-0.9, 0);
			glVertex2f(0.9f, 0);
			glVertex2f(0.9f, -0.9f);
			glVertex2f(-0.9f, -0.9f);
		}
		glEnd();

		break;
	case 1:
		// Negeri Sembilan
		glBegin(GL_QUADS);
		{
			glColor3ub(255, 255, 0);

			glVertex2f(-0.9f, 0.9f);
			glVertex2f(0.9f, 0.9f);
			glVertex2f(0.9f, -0.9f);
			glVertex2f(-0.9f, -0.9f);
		}
		glEnd();

		glBegin(GL_TRIANGLES);
		{
			glColor3ub(255, 0, 0);

			glVertex2f(-0.9f, 0.9f);
			glVertex2f(0, 0.9f);
			glVertex2f(0, 0);
		}
		glEnd();

		glBegin(GL_TRIANGLES);
		{
			glColor3ub(59, 0, 0);

			glVertex2f(-0.9f, 0.9f);
			glVertex2f(-0.9f, 0);
			glVertex2f(0, 0);
		}
		glEnd();

		break;
	case 2:
		// England
		glBegin(GL_QUADS);
		{
			glColor3ub(255, 255, 255);

			glVertex2f(-0.9f, 0.9f);
			glVertex2f(0.9f, 0.9f);
			glVertex2f(0.9f, -0.9f);
			glVertex2f(-0.9f, -0.9f);
		}
		glEnd();

		glBegin(GL_QUADS);
		{
			glColor3ub(255, 0, 0);

			glVertex2f(-0.15f, 0.9f);
			glVertex2f(0.15f, 0.9f);
			glVertex2f(0.15f, -0.9f);
			glVertex2f(-0.15f, -0.9f);
		}
		glEnd();

		glBegin(GL_QUADS);
		{
			glColor3ub(255, 0, 0);

			glVertex2f(-0.9f, 0.15f);
			glVertex2f(0.9f, 0.15f);
			glVertex2f(0.9f, -0.15f);
			glVertex2f(-0.9f, -0.15f);
		}
		glEnd();

		// Shaded
		glBegin(GL_QUADS);
		{
			glColor4f(0, 0, 0, 0.1f);

			glVertex2f(-0.9f, -0.9f);
			glVertex2f(0.9f, -0.9f);
			glVertex2f(0.9f, -0.8f);
			glVertex2f(-0.9f, -0.8f);
		}
		glEnd();

		glBegin(GL_QUADS);
		{
			glColor4f(0, 0, 0, 0.1f);

			glVertex2f(-0.9f, 0.9f);
			glVertex2f(0.9f, 0.9f);
			glVertex2f(0.9f, 0.8f);
			glVertex2f(-0.9f, 0.8f);
		}
		glEnd();

		glBegin(GL_QUADS);
		{
			glColor4f(0, 0, 0, 0.1f);

			glVertex2f(-0.9f, -0.8f);
			glVertex2f(-0.8f, -0.8f);
			glVertex2f(-0.8f, 0.8f);
			glVertex2f(-0.9f, 0.8f);
		}
		glEnd();

		glBegin(GL_QUADS);
		{
			glColor4f(0, 0, 0, 0.1f);

			glVertex2f(0.9f, -0.8f);
			glVertex2f(0.8f, -0.8f);
			glVertex2f(0.8f, 0.8f);
			glVertex2f(0.9f, 0.8f);
		}
		glEnd();

		glBegin(GL_TRIANGLES);
		{
			glColor4f(0, 0, 0, 0.1f);

			glVertex2f(0.7f, 0.8f);
			glVertex2f(0.8f, 0.7f);
			glVertex2f(0.8f, 0.8f);
		}
		glEnd();

		glBegin(GL_TRIANGLES);
		{
			glColor4f(0, 0, 0, 0.1f);

			glVertex2f(-0.7f, 0.8f);
			glVertex2f(-0.8f, 0.7f);
			glVertex2f(-0.8f, 0.8f);
		}
		glEnd();

		glBegin(GL_TRIANGLES);
		{
			glColor4f(0, 0, 0, 0.1f);

			glVertex2f(-0.7f, -0.8f);
			glVertex2f(-0.8f, -0.7f);
			glVertex2f(-0.8f, -0.8f);
		}
		glEnd();

		glBegin(GL_TRIANGLES);
		{
			glColor4f(0, 0, 0, 0.1f);

			glVertex2f(0.7f, -0.8f);
			glVertex2f(0.8f, -0.7f);
			glVertex2f(0.8f, -0.8f);
		}
		glEnd();

		break;
	case 3:
		// Scothland
		glBegin(GL_QUADS);
		{
			glColor3ub(0, 183, 255);

			glVertex2f(-0.9f, 0.9f);
			glVertex2f(0.9f, 0.9f);
			glVertex2f(0.9f, -0.9f);
			glVertex2f(-0.9f, -0.9f);
		}
		glEnd();

		glBegin(GL_POLYGON);
		{
			glColor3ub(255, 255, 255);

			glVertex2f(-0.9f, 0.9f);
			glVertex2f(-0.7f, 0.9f);
			glVertex2f(0.9f, -0.7f);
			glVertex2f(0.9, -0.9f);
			glVertex2f(0.7f, -0.9f);
			glVertex2f(-0.9f, 0.7f);
		}
		glEnd();

		glRotatef(90, 0, 0, 1);
		glBegin(GL_POLYGON);
		{
			glColor3ub(255, 255, 255);

			glVertex2f(-0.9f, 0.9f);
			glVertex2f(-0.7f, 0.9f);
			glVertex2f(0.9f, -0.7f);
			glVertex2f(0.9, -0.9f);
			glVertex2f(0.7f, -0.9f);
			glVertex2f(-0.9f, 0.7f);
		}
		glEnd();

		glRotatef(-90, 0, 0, 1);

		break;
	case 4:
		// Japan
		glBegin(GL_QUADS);
		{
			glColor3ub(255, 255, 255);

			glVertex2f(-0.9f, 0.9f);
			glVertex2f(0.9f, 0.9f);
			glVertex2f(0.9f, -0.9f);
			glVertex2f(-0.9f, -0.9f);
		}
		glEnd();

		glColor3ub(255, 0, 0);
		drawCircle(0.5);

		break;
	case 5:
		// Face Blue
		glPushMatrix();
		glColor3ub(0, 0, 0);
		drawCircle(0.505);
		glPopMatrix();

		glPushMatrix();
		glColor3ub(0, 229, 255);
		drawCircle(0.5);
		glPopMatrix();

		// Face White
		glPushMatrix();
		glTranslatef(0, -0.09, 0);
		glColor3ub(0, 0, 0);
		drawCircle(0.415);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, -0.09, 0);
		glColor3ub(255, 255, 255);
		drawCircle(0.41);
		glPopMatrix();

		// Left Eye
		glPushMatrix();
		glTranslatef(-0.103, 0.32, 0);
		glColor3ub(0, 0, 0);
		drawCircle(0.105);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.103, 0.32, 0);
		glColor3ub(255, 255, 255);
		drawCircle(0.10);
		glPopMatrix();

			// Pupil
		glPushMatrix();
		glTranslatef(-0.06, 0.32, 0);
		glColor3ub(0, 0, 0);
		drawCircle(0.033);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.06, 0.32, 0);
		glColor3ub(255, 255, 255);
		drawCircle(0.015);
		glPopMatrix();

		// Right Eye
		glPushMatrix();
		glTranslatef(0.103, 0.32, 0);
		glColor3ub(0, 0, 0);
		drawCircle(0.105);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.103, 0.32, 0);
		glColor3ub(255, 255, 255);
		drawCircle(0.10);
		glPopMatrix();
		
			// Pupil
		glPushMatrix();
		glTranslatef(0.06, 0.32, 0);
		glColor3ub(0, 0, 0);
		drawCircle(0.033);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.06, 0.32, 0);
		glColor3ub(255, 255, 255);
		drawCircle(0.015);
		glPopMatrix();

		// Nose
		glPushMatrix();
		glTranslatef(0, 0.2, 0);
		glColor3ub(0, 0, 0);
		drawCircle(0.06);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, 0.2, 0);
		glColor3ub(255, 0, 0);
		drawCircle(0.055);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.02, 0.21, 0);
		glColor3ub(255, 255, 255);
		drawCircle(0.022);
		glPopMatrix();

		// Mouth
		glLineWidth(1.5);

		glPushMatrix();
		glColor3ub(0, 0, 0);
		glBegin(GL_LINE_STRIP);
		glVertex2f(0, 0.145);
		glVertex2f(0, -0.4);
		glEnd();
		glPopMatrix();


			// Left
		glPushMatrix();
		glColor3ub(0, 0, 0);
		glTranslatef(-0.09, 0, 0);
		glRotatef(-90, 0, 0, 1);
		glBegin(GL_LINE_STRIP);
		glVertex2f(0, 0);
		glVertex2f(0, -0.22);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glColor3ub(0, 0, 0);
		glTranslatef(-0.08, -0.05, 0);
		glRotatef(-70, 0, 0, 1);
		glBegin(GL_LINE_STRIP);
		glVertex2f(0, 0);
		glVertex2f(0, -0.22);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glColor3ub(0, 0, 0);
		glTranslatef(-0.08, 0.05, 0);
		glRotatef(-110, 0, 0, 1);
		glBegin(GL_LINE_STRIP);
		glVertex2f(0, 0);
		glVertex2f(0, -0.22);
		glEnd();
		glPopMatrix();

			// Right
		glPushMatrix();
		glColor3ub(0, 0, 0);
		glTranslatef(0.09, 0, 0);
		glRotatef(90, 0, 0, 1);
		glBegin(GL_LINE_STRIP);
		glVertex2f(0, 0);
		glVertex2f(0, -0.22);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glColor3ub(0, 0, 0);
		glTranslatef(0.08, -0.05, 0);
		glRotatef(70, 0, 0, 1);
		glBegin(GL_LINE_STRIP);
		glVertex2f(0, 0);
		glVertex2f(0, -0.22);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glColor3ub(0, 0, 0);
		glTranslatef(0.08, 0.05, 0);
		glRotatef(110, 0, 0, 1);
		glBegin(GL_LINE_STRIP);
		glVertex2f(0, 0);
		glVertex2f(0, -0.22);
		glEnd();
		glPopMatrix();

			// Smile
		glPushMatrix();
		glColor3ub(0, 0, 0);
		glTranslatef(0, -0.1, 0);
		glRotatef(180, 1, 0, 0);
		glBegin(GL_LINE_STRIP);
		for (int ii = 0; ii < 100; ii++) {
			float theta = 3.1415926f * float(ii) / float(100);//get the current angle
			float x = 0.3f * cosf(theta);//calculate the x component
			float y = 0.3f * sinf(theta);//calculate the y component
			glVertex2f(x + 0, y + 0);//output vertex 
		}
		glEnd();
		glPopMatrix();

		// Belt
		glPushMatrix();
		glColor3ub(0, 0, 0);
		glTranslatef(0, -0.51, 0);
		glBegin(GL_QUADS);
		glVertex2f(-0.3, 0);
		glVertex2f(0.3, 0);
		glVertex2f(0.3, 0.1);
		glVertex2f(-0.3, 0.1);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glColor3ub(255, 0, 0);
		glTranslatef(0, -0.515, 0);
		glBegin(GL_QUADS);
		glVertex2f(-0.295, 0.01);
		glVertex2f(0.295, 0.01);
		glVertex2f(0.295, 0.095);
		glVertex2f(-0.295, 0.095);
		glEnd();
		glPopMatrix();

		// Bell
		glPushMatrix();
		glTranslatef(0, -0.52, 0);
		glColor3ub(0, 0, 0);
		drawCircle(0.085);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, -0.52, 0);
		glColor3ub(255, 255, 0);
		drawCircle(0.08);
		glPopMatrix();

		glPushMatrix();
		glColor3ub(0, 0, 0);
		glTranslatef(0, -0.55, 0);
		glBegin(GL_QUADS);
		glVertex2f(-0.085, 0);
		glVertex2f(0.085, 0);
		glVertex2f(0.085, 0.05);
		glVertex2f(-0.085, 0.05);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glColor3ub(255, 255, 0);
		glTranslatef(0, -0.55, 0);
		glBegin(GL_QUADS);
		glVertex2f(-0.08, 0.005);
		glVertex2f(0.08, 0.005);
		glVertex2f(0.08, 0.045);
		glVertex2f(-0.08, 0.045);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, -0.58, 0);
		glColor3ub(0, 0, 0);
		drawCircle(0.025);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, -0.58, 0);
		glColor3ub(161, 110, 0);
		drawCircle(0.02);
		glPopMatrix();

		break;
	}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.55f, 0.55f, 0.55f, 0);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);

	drawFlag(page);
}

//--------------------------------------------------------------------

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE prevInstance,
	_In_ LPSTR cmdLine, _In_ int nCmdShow) // FIXED
{
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hInstance = GetModuleHandle(NULL);
	wc.lpfnWndProc = WindowProcedure;
	wc.lpszClassName = WINDOW_TITLE;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&wc)) return false;

	HWND hWnd = CreateWindow(WINDOW_TITLE, WINDOW_TITLE, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
		NULL, NULL, wc.hInstance, NULL);

	//--------------------------------
	//	Initialize window for OpenGL
	//--------------------------------

	HDC hdc = GetDC(hWnd);

	//	initialize pixel format for the window
	initPixelFormat(hdc);

	//	get an openGL context
	HGLRC hglrc = wglCreateContext(hdc);

	//	make context current
	if (!wglMakeCurrent(hdc, hglrc)) return false;

	//--------------------------------
	//	End initialization
	//--------------------------------

	ShowWindow(hWnd, nCmdShow);

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		display();

		SwapBuffers(hdc);
	}

	UnregisterClass(WINDOW_TITLE, wc.hInstance);

	return true;
}
//--------------------------------------------------------------------
