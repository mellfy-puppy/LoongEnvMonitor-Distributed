#include <ArduinoMqttClient.h>
#include <ESP8266WiFi.h>
#include <DFRobot_DHT11.h>
#include <ArduinoJson.h>
DFRobot_DHT11 DHT;

#define DHT11_PIN 14  //D1
String value1;
String value2;
char ssid[] = "4ldl";    // your network SSID (name)
char pass[] = "213456789";    // your network password (use for WPA, or use as key for WEP)


WiFiClient wifiClient;
MqttClient mqttClient(wifiClient);

const char broker[]    = "iot-06z009xhkvpm7xx.mqtt.iothub.aliyuncs.com";
int        port        = 1883;

const char inTopic[]   = "/sys/k15u4pLbvWp/1c102_dev/thing/service/property/set";
const char outTopic[]  = "/sys/k15u4pLbvWp/1c102_dev/thing/event/property/post";

const long interval = 10000;
unsigned long previousMillis = 0;

int count = 0;

String inputString ="";

void setup() {value1=(String)30;
value2=(String)26;
  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  pinMode(2,OUTPUT);

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

  mqttClient.setId("k15u4pLbvWp.1c102_dev|securemode=2,signmethod=hmacsha256,timestamp=1716473883467|");                    //mqtt 连接客户端id
  mqttClient.setUsernamePassword("1c102_dev&k15u4pLbvWp", "c1ecef1c88870e491d163d8f0d7bb44b11d5f652dfc547c1f59a38c921601bb4");        //mqtt 连接用户名、密码

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


//{"deviceType":"CustomCategory","iotId":"fwJnX0wS4z4MbrzkyRlt000000","requ{estId":"1689847083906","checkFailedData":{},"productKey":"a1gfbOdKycU","gmtCreate":1689847087015,"deviceName":"app_dev","items":{"led":{"value":0,"time":1689847086996}}}
//{"deviceType":"CustomCategory","iotId":"lbyykAdhS5NkCnw4wQfdk15u40","requestId":"null","checkFailedData":{},"productKey":"k15u4pLbvWp","gmtCreate":1716608614895,"deviceName":"esp8266","items":{"temp":{"time":1716608614891,"value":26},"humi":{"time":1716608614891,"value":47}}}
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
      DynamicJsonDocument json_value1(1024);
      DynamicJsonDocument json_value2(1024);
      deserializeJson(json_msg,inputString);

      String items = json_msg["items"];

      deserializeJson(json_item,items);
      String temp = json_item["temp"];
       String humi = json_item["humi"];
      deserializeJson(json_value1,temp);
      value1 = (String)json_value1["value"];
       deserializeJson(json_value2,humi);
      value2 = (String)json_value2["value"];
    Serial.println("temp="+value1+","+"humi="+value2);

    }
  }
  Serial.println();

  Serial.println();
}
void loop(){delay(10000);Serial.println("temp="+value1+","+"humi="+value2);}
