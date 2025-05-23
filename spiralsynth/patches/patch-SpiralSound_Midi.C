$NetBSD$

2024-01-24: Patch modified for FLTK 1.4.

--- SpiralSound/Midi.C.orig	2002-06-11 22:08:56.000000000 +0000
+++ SpiralSound/Midi.C
@@ -24,7 +24,11 @@
 #include "pthread.h"
 
 #ifdef KEYBOARD_SUPPORT
-#include <FL/Fl.h>
+#include <FL/Fl.H>
+#endif
+
+#if defined(__DragonFly__) && !defined(O_SYNC)
+#define O_SYNC O_FSYNC
 #endif
 
 static const int MIDI_SCANBUFSIZE=256;
@@ -76,12 +80,12 @@ MidiDevice::~MidiDevice() 
 void MidiDevice::Close()
 {
 	pthread_mutex_lock(m_Mutex);
-	pthread_cancel(m_MidiReader); 
+	if (m_MidiReader != NULL)
+		pthread_cancel(m_MidiReader); 
 	pthread_mutex_unlock(m_Mutex);
 	pthread_mutex_destroy(m_Mutex);
 		
 	close(m_MidiFd);
-	close(m_MidiWrFd);
 	cerr<<"Closed midi device"<<endl;
 }
 
@@ -90,24 +94,19 @@ void MidiDevice::Open()
 {
 	//if (!SpiralInfo::WANTMIDI) return;
 	
-	m_MidiFd = open(m_DeviceName.c_str(),O_RDONLY|O_SYNC);  
-	if (!m_MidiFd) 
-	{
-		cerr<<"Couldn't open midi for reading ["<<m_DeviceName<<"]"<<endl;
-		return;
-	}
-	
-	m_MidiWrFd = open(m_DeviceName.c_str(),O_WRONLY);  
-	if (!m_MidiWrFd) 
+	m_Mutex = new pthread_mutex_t;
+    pthread_mutex_init(m_Mutex, NULL);
+	m_MidiReader = NULL;
+
+	m_MidiWrFd = m_MidiFd = open(m_DeviceName.c_str(),O_RDWR|O_SYNC);  
+	if (m_MidiFd == -1) 
 	{
-		cerr<<"Couldn't open midi for writing ["<<m_DeviceName<<"]"<<endl;
+		cerr<<"Couldn't open midi ["<<m_DeviceName<<"]"<<endl;
 		return;
 	}
 	
 	cerr<<"Opened midi device ["<<m_DeviceName<<"]"<<endl;
 	
-	m_Mutex = new pthread_mutex_t;
-    pthread_mutex_init(m_Mutex, NULL);
     int ret=pthread_create(&m_MidiReader,NULL,(void*(*)(void*))MidiDevice::MidiReaderCallback,(void*)this);	
 }
 
