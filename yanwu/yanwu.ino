#include <ArduinoMqttClient.h>
#include <ESP8266WiFi.h>
#include <ArduinoJson.h>


int bee=14;

char ssid[] = "4ldl";    // your network SSID (name)
char pass[] = "213456789";    // your network password (use for WPA, or use as key for WEP)


WiFiClient wifiClient;
MqttClient mqttClient(wifiClient);

const char broker[]    = "iot-06z009xhkvpm7xx.mqtt.iothub.aliyuncs.com";
int        port        = 1883;

const char inTopic[]   = "/sys/k15u4pLbvWp/yanwu/thing/service/property/set";
const char outTopic[]  = "/sys/k15u4pLbvWp/yanwu/thing/event/property/post";

const long interval = 30000;
unsigned long previousMillis = 0;

int count = 0;

String inputString ="";

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  pinMode(2,OUTPUT);
 pinMode(bee,INPUT_PULLUP);
  // attempt to connect to WiFi network:
  Serial.print("Attempting to connect to WPA SSID: ");
  Serial.println(ssid);
  while (WiFi.begin(ssid, pass) != WL_CONNECTED) {
    // failed, retry
    Serial.print(".");
    delay(5000);
  }

  Serial.println("You're connected to the network");
  Serial.println();

  mqttClient.setId("k15u4pLbvWp.yanwu|securemode=2,signmethod=hmacsha256,timestamp=1719328690004|");                    //mqtt 连接客户端id
  mqttClient.setUsernamePassword("yanwu&k15u4pLbvWp", "22ee4b2a469228321fdcc414c8be63e639618efa1131d9d33ee8574cc997a237");        //mqtt 连接用户名、密码

  Serial.print("Attempting to connect to the MQTT broker: ");
  Serial.println(broker);

  if (!mqttClient.connect(broker, port)) {
    Serial.print("MQTT connection failed! Error code = ");
    Serial.println(mqttClient.connectError());

    while (1);
  }

  Serial.println("You're connected to the MQTT broker!");
  Serial.println();

  // set the message receive callback
  mqttClient.onMessage(onMqttMessage);

  Serial.print("Subscribing to topic: ");
  Serial.println(inTopic);
  Serial.println();

  int subscribeQos = 1;

  mqttClient.subscribe(inTopic, subscribeQos);

  // topics can be unsubscribed using:
  // mqttClient.unsubscribe(inTopic);

  Serial.print("Waiting for messages on topic: ");
  Serial.println(inTopic);
  Serial.println();
}

void loop() {

  mqttClient.poll();


  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval+5000) {
    // save the last time a message was sent
    previousMillis = currentMillis;

    String payload;

   

    //{"params":{"temp":1.22,"humi":22},"version":"1.0.0"}
  
  
DynamicJsonDocument json_msg(512);
     DynamicJsonDocument json_data(512);
   

    json_data["bee"] = digitalRead(bee) ;


    json_msg["params"] = json_data;
    json_msg["version"] = "1.0.0";

    delay(10000);
    serializeJson(json_msg,payload);

    Serial.print("Sending message to topic: ");
    Serial.println(outTopic);
    
    Serial.println(payload);


    bool retained = false;
    int qos = 1;
    bool dup = false;

    mqttClient.beginMessage(outTopic, payload.length(), retained, qos, dup);
    mqttClient.print(payload);
    mqttClient.endMessage();

    Serial.println();

    count++;
  }
  
}

//{"deviceType":"CustomCategory","iotId":"fwJnX0wS4z4MbrzkyRlt000000","requestId":"1689847083906","checkFailedData":{},"productKey":"a1gfbOdKycU","gmtCreate":1689847087015,"deviceName":"app_dev","items":{"led":{"value":0,"time":1689847086996}}}

void onMqttMessage(int messageSize) {
  // we received a message, print out the topic and contents
  Serial.print("Received a message with topic '");
  Serial.print(mqttClient.messageTopic());
  Serial.print("', duplicate = ");
  Serial.print(mqttClient.messageDup() ? "true" : "false");
  Serial.print(", QoS = ");
  Serial.print(mqttClient.messageQoS());
  Serial.print(", retained = ");
  Serial.print(mqttClient.messageRetain() ? "true" : "false");
  Serial.print("', length ");
  Serial.print(messageSize);
  Serial.println(" bytes:");

  // use the Stream interface to print the contents
  while (mqttClient.available()) {
    char inChar =(char)mqttClient.read();
    inputString +=inChar;
    if(inputString.length()==messageSize) {

      DynamicJsonDocument json_msg(1024);
      DynamicJsonDocument json_item(1024);
      DynamicJsonDocument json_value(1024);

      deserializeJson(json_msg,inputString);

      String items = json_msg["items"];

      deserializeJson(json_item,items);
      String led = json_item["led"];

      deserializeJson(json_value,led);
      bool value = json_value["value"];

      if(value ==0) {
        //关
        Serial.println("off");
        digitalWrite(2,1);
      } else {
        //开
        Serial.println("on");
        digitalWrite(2,0);
      }
      inputString="";
    }


  }
  Serial.println();

  Serial.println();
}
