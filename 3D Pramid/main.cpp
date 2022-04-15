#include <windows.h> 
#include <GL/glut.h>  
 
/* Global deðiþkenler  */
char title[] = "3 Boyutlu Sekil";
 
/* OpenGL Graphics'i baþlat */
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Arka plan rengini siyah ve opak olarak ayarladým
   glClearDepth(1.0f);                   // Arka plan derinliðini en uzak noktaya ayarladým 
   glEnable(GL_DEPTH_TEST);   // z-culling için derinlik testini etkinleþtirdim 
   glDepthFunc(GL_LEQUAL);    // Derinlik testi türünü ayarladým 
   glShadeModel(GL_SMOOTH);   // Düzgün gölgelendirmeyi etkinleþtirdim
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // perspektif düzeltmelerini yaptým
   

}
 
void display() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Renk ve derinlik tamponlarýný temizle 
   glMatrixMode(GL_MODELVIEW);     // Modelve görünüm matrisin üzerinde çalýþmak içindir.
 
   // 4 üçgenden oluþan bir piramit oluþturdum
   glLoadIdentity();                  // Model görünüm matrisini sýfýrladým
   glTranslatef(-1.5f, 0.0f, -6.0f);  // ekranýn sol tarafýna yönlendirdim button eklemek için saða
 
   glBegin(GL_TRIANGLES);           // Piramidi 4 üçgenle çizmeye baþladým ve bunun þemasýný word üzerinden raporuma ekleme yapcaðým
      // Pramdin Ön yüzü
      glColor3f(1.0f, 0.0f, 0.0f);     // Kýrmýzý renk
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Yeþil renk
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Mavi renk
      glVertex3f(1.0f, -1.0f, 1.0f);
 
      // Pramidin sað tarafý
      glColor3f(1.0f, 0.0f, 0.0f);     //Kýrmýzý
      glVertex3f(0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Mavi 
      glVertex3f(1.0f, -1.0f, 1.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // yeþil
      glVertex3f(1.0f, -1.0f, -1.0f);
 
      // Pramidin arka tarafý
      glColor3f(1.0f, 0.0f, 0.0f);     // Kýrmýzý
      glVertex3f(0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Yeþil
      glVertex3f(1.0f, -1.0f, -1.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Mavi
      glVertex3f(-1.0f, -1.0f, -1.0f);
 
      // pramidin sol tarafý
      glColor3f(1.0f,0.0f,0.0f);       // Kýrmýzý 
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glColor3f(0.0f,0.0f,1.0f);       // Mavi
      glVertex3f(-1.0f,-1.0f,-1.0f);
      glColor3f(0.0f,1.0f,0.0f);       // Yeþil
      glVertex3f(-1.0f,-1.0f, 1.0f);
   glEnd();   // Piramidin çizilmesi tamamlandý.
   
/*   GLfloat xspeed;
   GLfloat yspeed;
   GLfloat z=-5.0f;
   GLfloat xrot;
   GLfloat yrot;
   glTranslatef(0.0f,0.0f, -2.0f); // þekli merkeze taþýdýk , z eksenin de iki birim ilerlettik
   glRotatef(xrot,0.0f,1.0f, 0.0f);
   glRotatef(yrot,1.0f,0.0f,0.0f);
   xrot += xspeed;
  yrot += yspeed;
  if (PeekMessage(&msg,NULL,0,0,PM_REMOVE))
{
….
}
else
{
…..
else
{
SwapBuffers(hDC);
if (keys[VK_UP])
{
yspeed+=0.01f; // yukarý yöntuþuna basýlýrsa
}
if (keys[VK_DOWN])
{
yspeed-=0.01f; //aþaðý yöntuþuna basýlýrsa
}
if (keys[VK_RIGHT])
{
xspeed+=0.01f; //sað yöntuþuna basýlýrsa
}
if (keys[VK_LEFT])
{
xspeed-=0.01f; //sol yöntuþuna basýlýrsa

}
…
}
xrot += xspeed; // alýnan hýz deðerleri xrot ve yrot deðiþkenlerine aktarýlýyor

yrot += yspeed;

glTranslatef(0.0f,0.0f, 2.0f); // þekli z ekesninde 2 birim götürmüþtük ayný miktarda geri getirdik */ /*Hocam þekli döndürme iþini baþarý ile gerçekleþtiremedim*/
 
   glutSwapBuffers();  // Ön ve arka çerçeve arabelleklerini deðiþtirdim (çift arabelleðe alma þeklinde ) 
}
 
/* Pencere yeniden boyutlandýrma etkinliði için Ýþleyici. Pencere ilk göründüðünde ve 
   pencere yeni geniþliði ve yüksekliðiyle yeniden boyutlandýrýldýðýnda geri çaðrýlmasý yapýlýr. */
void reshape(GLsizei width, GLsizei height) {  // GLsizei kullanma amacým negatif olmayan tam sayý için
   // Yeni pencerenin en ve boy oranýný hesaplatýrdým
   if (height == 0) height = 1;                // sýfýra bölünmesini önlemek için 
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
 
   //Görüntü alanýný yeni pencereyi kaplayacak þekilde ayarladým
   glViewport(0, 0, width, height);
 
   //Kýrpma hacminin en boy oranýný görüntü alanýna uyacak þekilde ayarladým
   glMatrixMode(GL_PROJECTION);  
   glLoadIdentity();             
   //projeksiyon etkinleþtirme iþlemini gerçekleþtirdim
   gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}
 
/* Main yani ana iþlevini glut ana programdan baþlayarak bir konsol uygulamasý olarak çalýþtýrdým.() */
int main(int argc, char** argv) {
   glutInit(&argc, argv);            // Glutu baþlattým
   glutInitDisplayMode(GLUT_DOUBLE); // Çift arabelleðe alýnmýþ modu etkinleþtirdim.
   glutInitWindowSize(640, 480);   //Pencerenin baþlangýç geniþliðini ve yüksekliðini ayarladým.
   glutInitWindowPosition(50, 50); // Pencerenin ilk sol üst köþesini konumlandýrdým.
   glutCreateWindow(title);          //Verilen baþlýða sahip pencere oluþturdum.
   glutDisplayFunc(display);       // Pencere yeniden boyama olayý için geri arama iþleyicisini kayýt etme fonkisyonunu gerçekleþtirdim.
   glutReshapeFunc(reshape);       // Arama iþleyicisini kaydettim.
   initGL();                       
   glutMainLoop();                
  
   return 0;
}

