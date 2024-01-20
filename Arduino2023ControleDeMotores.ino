#include <AFMotor.h>

AF_DCMotor motor1(1); // Cria objetos que representa os motores 
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);


// Mapeia os valores dos joysticks para a faixa de velocidade dos motores

  int motorSpeed1 = map(y1Value, 0, 1023, -motorSpeedMax, motorSpeedMax);
  int motorSpeed2 = map(x1Value, 0, 1023, -motorSpeedMax, motorSpeedMax);
  int motorSpeed3 = map(y2Value, 0, 1023, -motorSpeedMax, motorSpeedMax);
  int motorSpeed4 = map(x2Value, 0, 1023, -motorSpeedMax, motorSpeedMax);

// Aciona os motores individualmente com base nos valores dos joysticks

  motor1.setSpeed(abs(motorSpeed1));
  motor2.setSpeed(abs(motorSpeed2));
  motor3.setSpeed(abs(motorSpeed3));
  motor4.setSpeed(abs(motorSpeed4));


// Se a velocidade for maior que zero que seria 255(motorSpeedMax) positivo, o motor gira pra Direita
se a velocidade for negativa -255(-motorSpeedMax) o motor gira para Esquerda. 

  if (motorSpeed1 >= 0) {
    motor1.run(FORWARD);
  } else {
    motor1.run(BACKWARD);
  }

  if (motorSpeed2 >= 0) {
    motor2.run(FORWARD);
  } else {
    motor2.run(BACKWARD);
  }

  if (motorSpeed3 >= 0) {
    motor3.run(FORWARD);
  } else {
    motor3.run(BACKWARD);
  }
 
  if (motorSpeed4 >= 0) {
    motor4.run(FORWARD);
  } else {
    motor4.run(BACKWARD);
  }

  // Imprime os valores dos botões joystick acionados no Monitor Serial
  Serial.print("Joystick 1 - Eixo X: ");
  Serial.print(x1Value);
  Serial.print("\tEixo Y: ");
  Serial.println(y1Value);

  Serial.print("Joystick 2 - Eixo X: ");
  Serial.print(x2Value);
  Serial.print("\tEixo Y: ");
  Serial.println(y2Value);
}
