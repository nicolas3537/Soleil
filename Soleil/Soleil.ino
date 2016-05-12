// gestion des sorties
const int ledR = 3;
const int ledG = 4;
const int ledB = 5;
// gestion des entrées
const int potR = A1;
const int potG = A2;
const int potB = A4;
const int PosSoleil = A5;
// gestion des variable global
// boolean Etat = true; // true = Soleil et False = Lune à rajouter si juste changement d'état
int Position_Soleil = 0;
int choix =2;

void setup() {
  // put your setup code here, to run once:
  //Définition des sorties
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
  //Définition des entrées
  pinMode(potR, INPUT);
  pinMode(potG, INPUT);
  pinMode(potB, INPUT);
  //Gestion de la liaison série
  Serial.begin(115200);
  Serial.println("Hello");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (choix ==1) {
  // commande Rouge
  int ValeurR = analogRead(potR);
  int ComR = map(ValeurR, 0,1023, 0 ,255);
  Serial.print("Valeur Rouge : ");
  Serial.print(ComR);
  Serial.print("\t");
  analogWrite(ledR, ComR);
// commande Vert
 int ValeurG = analogRead(potG);
 int ComG = map(ValeurG, 0,1023, 0 ,255);
 Serial.print("valeur Vert : ");
  Serial.print(ComG);
  Serial.print("\t");
 analogWrite(ledG, ComG);
// commande Blue
 int ValeurB = analogRead(potB);
 int ComB = map(ValeurB, 0,1023, 0 ,255);
 Serial.print("valeur Bleu : ");
 Serial.println(ComB);
 analogWrite(ledB, ComB);
  }
 if (choix == 2 ){
 PositionSoleil();
 }
 
}

void PositionSoleil () {
// récupérer la position du soleil
  int last_Pos_Soleil = Position_Soleil;
  Position_Soleil = analogRead(PosSoleil);
  //Position_Soleil = map(Position_Soleil, 0 , 1023 , 0 ,1023);
  Serial.print("Position du soleil ");
  Serial.println(Position_Soleil);
  //Serial.print("\t");
  //Serial.print("Etat : ");
  //Serial.println(Etat);
  //Allumer en soleil
  if ( (Position_Soleil >= 0 and Position_Soleil <= 115) and last_Pos_Soleil < Position_Soleil ) {  // pour gérer juste un changement d'état en buté remplacer le dernier et par ceci and Etat == 1
      // Création du fadding entre le matin et la journée
      int Red = map ( Position_Soleil , 0 , 115 , 180, 201);
      int Green = map ( Position_Soleil , 0 , 115 , 176, 255);
      int Blue = map ( Position_Soleil , 0 , 115 , 28, 69);
      affichage_Couleur(Red,Green,Blue,"Matin");
      ComLumiere(Red, Green, Blue);
  }
  if ( (Position_Soleil > 115 and Position_Soleil <= 980) and last_Pos_Soleil < Position_Soleil ) {  // pour gérer juste un changement d'état en buté remplacer le dernier et par ceci and Etat == 1
      // Création du fadding entre la journée et le soir
      int Red = map ( Position_Soleil , 115 , 980 , 201, 186);
      int Green = map ( Position_Soleil , 115 , 980 , 255, 153);
      int Blue = map ( Position_Soleil , 115 , 980 , 69, 28);
      affichage_Couleur(Red,Green,Blue,"Journee");
      ComLumiere(Red, Green, Blue);
  }
  if ( (Position_Soleil > 980 and Position_Soleil <= 1023) and last_Pos_Soleil < Position_Soleil ) {  // pour gérer juste un changement d'état en buté remplacer le dernier et par ceci and Etat == 1
      // Création du fadding entre le soir et la lune
      int Red = map ( Position_Soleil , 980 , 1023 , 186, 0);
      int Green = map ( Position_Soleil , 980 , 1023 , 153, 0);
      int Blue = map ( Position_Soleil , 980 , 1023 ,28, 0);
      affichage_Couleur(Red,Green,Blue,"Soiree");
      ComLumiere(Red, Green, Blue);
      if (Position_Soleil == 1023) {
      //Etat = false;  à rajouter si juste changement d'état
      }
  }
  //Allumer en Lune
  if ( (Position_Soleil <= 1023 and Position_Soleil >= 980) and last_Pos_Soleil > Position_Soleil ) {  // pour gérer juste un changement d'état en buté remplacer le dernier et par ceci and Etat == 0
      // Création du fadding entre le matin et la journée
      int Red = map ( Position_Soleil , 1023 , 980 , 90, 135);
      int Green = map ( Position_Soleil , 1023 , 980 ,168, 255);
      int Blue = map ( Position_Soleil , 1023 , 980 , 53, 255);
      affichage_Couleur(Red,Green,Blue,"Matin");
      ComLumiere(Red, Green, Blue);
  }
  if ( (Position_Soleil < 980 and Position_Soleil >= 115) and last_Pos_Soleil > Position_Soleil ) {  // pour gérer juste un changement d'état en buté remplacer le dernier et par ceci and Etat == 0
      // Création du fadding entre la journée et le soir
      int Red = map ( Position_Soleil , 980 , 115 , 135, 166);
      int Green = map ( Position_Soleil , 980 , 115 , 255, 234);
      int Blue = map ( Position_Soleil , 980 , 115 , 255, 140);
      affichage_Couleur(Red,Green,Blue,"Journee");
      ComLumiere(Red, Green, Blue);
  }
  if ( (Position_Soleil < 115 and Position_Soleil >= 0) and last_Pos_Soleil > Position_Soleil ) {  // pour gérer juste un changement d'état en buté remplacer le dernier et par ceci and Etat == 0
      // Création du fadding entre le soir et la lune
      int Red = map ( Position_Soleil , 115 , 0 , 166, 0);
      int Green = map ( Position_Soleil , 115 , 0 , 234, 0);
      int Blue = map ( Position_Soleil , 115 , 0 ,140, 0);
      affichage_Couleur(Red,Green,Blue,"Soiree");
      ComLumiere(Red, Green, Blue);
      if (Position_Soleil == 1023) {
      //Etat = false; à rajouter si juste changement d'état
      }
  }
  
}

void ComLumiere (int Red, int Green, int Blue) {
  analogWrite(ledR, Red);
  analogWrite(ledG, Green);
  analogWrite(ledB, Blue);
}

void affichage_Couleur (int Red, int Green, int Blue, char moment[]) {
      Serial.println(moment);
      Serial.print("Rouge : ");
      Serial.print(Red);
      Serial.print("\t");
      Serial.print("Vert : ");
      Serial.print(Green);
      Serial.print("\t");
      Serial.print("Bleu : ");
      Serial.println(Blue);
}



