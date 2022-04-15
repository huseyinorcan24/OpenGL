#include <windows.h> 
#include <GL/glut.h>  
 
/* Global de�i�kenler  */
char title[] = "3 Boyutlu Sekil";
 
/* OpenGL Graphics'i ba�lat */
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Arka plan rengini siyah ve opak olarak ayarlad�m
   glClearDepth(1.0f);                   // Arka plan derinli�ini en uzak noktaya ayarlad�m 
   glEnable(GL_DEPTH_TEST);   // z-culling i�in derinlik testini etkinle�tirdim 
   glDepthFunc(GL_LEQUAL);    // Derinlik testi t�r�n� ayarlad�m 
   glShadeModel(GL_SMOOTH);   // D�zg�n g�lgelendirmeyi etkinle�tirdim
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // perspektif d�zeltmelerini yapt�m
   

}
 
void display() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Renk ve derinlik tamponlar�n� temizle 
   glMatrixMode(GL_MODELVIEW);     // Modelve g�r�n�m matrisin �zerinde �al��mak i�indir.
 
   // 4 ��genden olu�an bir piramit olu�turdum
   glLoadIdentity();                  // Model g�r�n�m matrisini s�f�rlad�m
   glTranslatef(-1.5f, 0.0f, -6.0f);  // ekran�n sol taraf�na y�nlendirdim button eklemek i�in sa�a
 
   glBegin(GL_TRIANGLES);           // Piramidi 4 ��genle �izmeye ba�lad�m ve bunun �emas�n� word �zerinden raporuma ekleme yapca��m
      // Pramdin �n y�z�
      glColor3f(1.0f, 0.0f, 0.0f);     // K�rm�z� renk
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Ye�il renk
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Mavi renk
      glVertex3f(1.0f, -1.0f, 1.0f);
 
      // Pramidin sa� taraf�
      glColor3f(1.0f, 0.0f, 0.0f);     //K�rm�z�
      glVertex3f(0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Mavi 
      glVertex3f(1.0f, -1.0f, 1.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // ye�il
      glVertex3f(1.0f, -1.0f, -1.0f);
 
      // Pramidin arka taraf�
      glColor3f(1.0f, 0.0f, 0.0f);     // K�rm�z�
      glVertex3f(0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Ye�il
      glVertex3f(1.0f, -1.0f, -1.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Mavi
      glVertex3f(-1.0f, -1.0f, -1.0f);
 
      // pramidin sol taraf�
      glColor3f(1.0f,0.0f,0.0f);       // K�rm�z� 
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glColor3f(0.0f,0.0f,1.0f);       // Mavi
      glVertex3f(-1.0f,-1.0f,-1.0f);
      glColor3f(0.0f,1.0f,0.0f);       // Ye�il
      glVertex3f(-1.0f,-1.0f, 1.0f);
   glEnd();   // Piramidin �izilmesi tamamland�.
   
/*   GLfloat xspeed;
   GLfloat yspeed;
   GLfloat z=-5.0f;
   GLfloat xrot;
   GLfloat yrot;
   glTranslatef(0.0f,0.0f, -2.0f); // �ekli merkeze ta��d�k , z eksenin de iki birim ilerlettik
   glRotatef(xrot,0.0f,1.0f, 0.0f);
   glRotatef(yrot,1.0f,0.0f,0.0f);
   xrot += xspeed;
  yrot += yspeed;
  if (PeekMessage(&msg,NULL,0,0,PM_REMOVE))
{
�.
}
else
{
�..
else
{
SwapBuffers(hDC);
if (keys[VK_UP])
{
yspeed+=0.01f; // yukar� y�ntu�una bas�l�rsa
}
if (keys[VK_DOWN])
{
yspeed-=0.01f; //a�a�� y�ntu�una bas�l�rsa
}
if (keys[VK_RIGHT])
{
xspeed+=0.01f; //sa� y�ntu�una bas�l�rsa
}
if (keys[VK_LEFT])
{
xspeed-=0.01f; //sol y�ntu�una bas�l�rsa

}
�
}
xrot += xspeed; // al�nan h�z de�erleri xrot ve yrot de�i�kenlerine aktar�l�yor

yrot += yspeed;

glTranslatef(0.0f,0.0f, 2.0f); // �ekli z ekesninde 2 birim g�t�rm��t�k ayn� miktarda geri getirdik */ /*Hocam �ekli d�nd�rme i�ini ba�ar� ile ger�ekle�tiremedim*/
 
   glutSwapBuffers();  // �n ve arka �er�eve arabelleklerini de�i�tirdim (�ift arabelle�e alma �eklinde ) 
}
 
/* Pencere yeniden boyutland�rma etkinli�i i�in ��leyici. Pencere ilk g�r�nd���nde ve 
   pencere yeni geni�li�i ve y�ksekli�iyle yeniden boyutland�r�ld���nda geri �a�r�lmas� yap�l�r. */
void reshape(GLsizei width, GLsizei height) {  // GLsizei kullanma amac�m negatif olmayan tam say� i�in
   // Yeni pencerenin en ve boy oran�n� hesaplat�rd�m
   if (height == 0) height = 1;                // s�f�ra b�l�nmesini �nlemek i�in 
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
 
   //G�r�nt� alan�n� yeni pencereyi kaplayacak �ekilde ayarlad�m
   glViewport(0, 0, width, height);
 
   //K�rpma hacminin en boy oran�n� g�r�nt� alan�na uyacak �ekilde ayarlad�m
   glMatrixMode(GL_PROJECTION);  
   glLoadIdentity();             
   //projeksiyon etkinle�tirme i�lemini ger�ekle�tirdim
   gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}
 
/* Main yani ana i�levini glut ana programdan ba�layarak bir konsol uygulamas� olarak �al��t�rd�m.() */
int main(int argc, char** argv) {
   glutInit(&argc, argv);            // Glutu ba�latt�m
   glutInitDisplayMode(GLUT_DOUBLE); // �ift arabelle�e al�nm�� modu etkinle�tirdim.
   glutInitWindowSize(640, 480);   //Pencerenin ba�lang�� geni�li�ini ve y�ksekli�ini ayarlad�m.
   glutInitWindowPosition(50, 50); // Pencerenin ilk sol �st k��esini konumland�rd�m.
   glutCreateWindow(title);          //Verilen ba�l��a sahip pencere olu�turdum.
   glutDisplayFunc(display);       // Pencere yeniden boyama olay� i�in geri arama i�leyicisini kay�t etme fonkisyonunu ger�ekle�tirdim.
   glutReshapeFunc(reshape);       // Arama i�leyicisini kaydettim.
   initGL();                       
   glutMainLoop();                
  
   return 0;
}

