// micros, by lmcapacho
import processing.serial.*;

Maze maze;

// El puerto serial
Serial myPort;

void setup() {

  // Tamaño de la ventana
  size(640, 640);

  // Tamaño fuente
  textSize(20);
  // Color de fondo de la ventana 
  background(255);
  // Alineación del texto
  textAlign(CENTER, CENTER);

  // Crea una nueva cuadrícula de 10 x 10   
  maze = new Maze(10);
  //Abre el puerto serial con velocidad de 9600 baudios
  myPort = new Serial(this, "COM5", 9600);
  myPort.clear(); 
}

void draw() {
  maze.display();
  
  while (myPort.available() > 0) {
    byte[] inBuffer = new byte[10];
    if( myPort.readBytesUntil('\n', inBuffer) > 0){
      maze.setMouse(inBuffer[0],inBuffer[1]);
    }  
  }
}