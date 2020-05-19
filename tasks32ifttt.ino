int photoresistor = A0;
bool Sunlight = false;


void setup() {
    pinMode(photoresistor,INPUT);
}

void loop() {
    int sun = analogRead(photoresistor);
    Particle.publish("sun", String(sun));
    
    if(sun <20 && !Sunlight){
        Particle.publish("Sunlight", "On");
        Sunlight = true;
        
    }else if (sun > 20 && Sunlight){
        Particle.publish("Sunlight", "Off");
        Sunlight = false;
    }
    delay(5000);    
}
