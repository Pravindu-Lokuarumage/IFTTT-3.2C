int photoresistor = A0;
bool Sunlight = false;
int light;

void setup() {
    pinMode(photoresistor,INPUT);
}

void loop() {
    light = analogRead(photoresistor);
    Particle.publish("sun", String(light));
    
    if(light <20 && !Sunlight){
        Particle.publish("Sunlight", "On");
        Sunlight = true;
        
    }else if (light > 20 && Sunlight){
        Particle.publish("Sunlight", "Off");
        Sunlight = false;
    }
    delay(5000);    
}
