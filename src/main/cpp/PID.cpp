/*
double Kp;
double Ki;
double Kd;
double error; //current error
double previousError; //error of time minus one time step
double dt; //time step
double t; //total time elapsed
double integralOfError = error * dt * (t / dt);
double derivativeOfError = (error - previousError) / dt;
double pidOutput = Kp * error + Ki * integralOfError + Kd * derivativeOfError;
while (true) {
    // Update error value here
    integralOfError += error * dt;
    derivativeOfError = (error - previousError) / dt;
    pidOutput = Kp * error + Ki * integralOfError + Kd * derivativeOfError;
    previousError = error;
    // Use pidOutput to control the system
}
*/