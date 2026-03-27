# 42BYGH48-motor-control
Development of a python code to control both velocity and position of a 42BYGH48 stepper motor

### Requerimientos del proyecto 
- Desarrollar un módulo en Python para el control a nivel de posición y velocidad del mecanismo lineal.
- Describir el estado actual del robot, el último comando de control y el tiempo esperado para realizarlo.
- Poder mandar comandos que reescriban el último comando de control enviado.
- El control en bajo nivel deberá implementar un controlador PID para la realización de sus comandos en bajo nivel.
- El módulo de control deberá ser posible usar con otros módulos de control para otros grados de libertad de la plataforma.

### Descripción de alto nivel del esquema de control
<img width="915" height="395" alt="image" src="https://github.com/user-attachments/assets/cd8a2557-9c27-4454-8a0e-f3a7e516dfc7" />

### Materiales necesarios.
Para las etapas de desarrollo, implementación y prototipado de este sistema, se tienen pensados los siguientes materiales:
-Motor 42BYGH48
-Driver DRV8825
-Fuente de voltaje 12V, 2-3A
-ESP32 
-2 Capacitores de 100 micro Faradios
-Protoboard y cableado
