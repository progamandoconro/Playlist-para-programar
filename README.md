# Playlist-para-programar
Mi música favorita para escuchar mientras escribo código 

Escucha canciones al azar en Raspberry conectada a Arduino Micro. 

  Requerimientos: 
  
  - Arduino Leonardo o Micro, Raspberry pi (or cualquier computadora). Cornetas o audífonos.  
  - Instala vlc (``sudo apt install vlc``).
  - Clona este repo en ``/home/pi`` (modifica si necesitas).
  
  Arduino Micro envía un mensaje a vlc para tocar una canción al azar en la Raspberry cuando un botón es apretado.
  
  El circuito:
  - Botón desde pin 4 a +5V
  - Resistencia 10 kilohm al pin 4 y ground
  - Conectar a Raspberry Pi
  - Conectar a cornetas
  - Aprieta el botón para una canción al azar 
  - Aprieta de nuevo para una nueva canción
  - Utiliza el botón de reset para detener la música
  - Una cerveza y Rock and Roll
  
  
<html> <img src="https://github.com/programandoconro/Playlist-para-programar/blob/master/arduraspi.png" /> </html>


** También puedes instalar ``termux`` en tu celular desde google-play, luego instalar play-audio en termux ``pkg install play-audio`` y git ``pkg install git``, clonar este repo ``git clone https://github.com/programandoconro/Playlist-para-programar``, entrar a la carpeta clonada y ejecutar ``sh random-music.sh``.

Agrega más canciones mp3 a Soundtrack y crea un pull request. 

Disfruta!  
