#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>      
#include <ESP_Mail_Client.h>

#define WIFI_SSID "Blue_Ternate_WIFI"
#define WIFI_PASSWORD "Blue_Ternate_WIFI_2024"
#define SMTP_HOST "smtp.gmail.com"

#define FIREBASE_HOST "blueternatevendo-default-rtdb.asia-southeast1.firebasedatabase.app"
#define FIREBASE_AUTH "0YMo67KmaGG3qtCvLc44Wj72k1gcnggyGPZN2cqO"           

#define SMTP_PORT 465
#define AUTHOR_EMAIL "vendoblueternate@gmail.com"
#define AUTHOR_PASSWORD "mlcg ttmf ossm ioyr"
SMTPSession smtp;
void smtpCallback(SMTP_Status status);

String messageTen = "<p style=\"max-width: 600px; font-family: Helvetica, sans-serif; font-size: 16px; text-align: justify !important; "
                      "color: black !important;\">Hi there,<br /><br />"
                      "<span>"
                      "We would like to inform you that certain products in the vending machine inventory are set to expire in the next 10 days. " 
                      "It is crucial to take prompt action to manage the inventory effectively and ensure the continued freshness and quality "
                      "of the products.</span><br /><br /> Best regards,<br /> Blue Ternate Vending Machine System"
                      "<p style=\"text-align: center; color: grey !important; max-width: 600px;\">&copy; 2024 Blue Ternate Vending Machine System."
                      "<br />\This is an automated notification from the Blue Ternate Vending Machine. All rights reserved.\</p></p>";
String messageFive = "<p style=\"max-width: 600px; font-family: Helvetica, sans-serif; font-size: 16px; text-align: justify !important; "
                      "color: black !important;\">Hi there,<br /><br />"
                      "<span>"
                      "We would like to inform you that certain products in the vending machine inventory are set to expire in the next 5 days. " 
                      "It is crucial to take prompt action to manage the inventory effectively and ensure the continued freshness and quality "
                      "of the products.</span><br /><br /> Best regards,<br /> Blue Ternate Vending Machine System"
                      "<p style=\"text-align: center; color: grey !important; max-width: 600px;\">&copy; 2024 Blue Ternate Vending Machine System."
                      "<br />\This is an automated notification from the Blue Ternate Vending Machine. All rights reserved.\</p></p>";
String messageThree = "<p style=\"max-width: 600px; font-family: Helvetica, sans-serif; font-size: 16px; text-align: justify !important; "
                      "color: black !important;\">Hi there,<br /><br />"
                      "<span>"
                      "We would like to inform you that certain products in the vending machine inventory are set to expire in the next 3 days. " 
                      "It is crucial to take prompt action to manage the inventory effectively and ensure the continued freshness and quality "
                      "of the products.</span><br /><br /> Best regards,<br /> Blue Ternate Vending Machine System"
                      "<p style=\"text-align: center; color: grey !important; max-width: 600px;\">&copy; 2024 Blue Ternate Vending Machine System."
                      "<br />\This is an automated notification from the Blue Ternate Vending Machine. All rights reserved.\</p></p>";
String messageExpired = "<p style=\"max-width: 600px; font-family: Helvetica, sans-serif; font-size: 16px; text-align: justify !important; "
                      "color: black !important;\">Hi there,<br /><br />"
                      "<span>We regret to inform you that certain products in the vending machine inventory have already expired. The machine "
                      "has been temporarily disabled to prevent the distribution of expired items. Please take immediate action to replace the "
                      "expired products and enable the machine for continued service."
                      "</span><br /><br /> Best regards,<br /> Blue Ternate Vending Machine System"
                      "<p style=\"text-align: center; color: grey !important; max-width: 600px;\">&copy; 2024 Blue Ternate Vending Machine System."
                      "<br />\This is an automated notification from the Blue Ternate Vending Machine. All rights reserved.\</p></p>";


bool vendoStatus = false;
int vendoExpDays = 0;
String messageToSent = "";
bool tenNotifSent = true;
bool fiveNotifSent = true;
bool threeNotifSent = true;
bool expNotifSent = true;
const int ledPin = D5;
void setup()
{
  Serial.begin(115200);
  Serial.println();
  pinMode(ledPin, OUTPUT);
  Serial.print("Connecting to AP");

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW); 
    delay(200);
  }

  Serial.println("");
  digitalWrite(ledPin, HIGH);
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println();
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  vendoStatus = Firebase.getBool("Vendo_Status");
  vendoExpDays = Firebase.getInt("Expiration_Days");

  tenNotifSent = Firebase.getBool("tenDaysNotifSent");
  fiveNotifSent = Firebase.getBool("fiveDaysNotifSent");
  threeNotifSent = Firebase.getBool("threeDaysNotifSent");
  expNotifSent = Firebase.getBool("expiredNotifSent"); 
}
  
void loop()
{   
  Serial.println("Notif10: " + String(tenNotifSent));
  Serial.println("Notif5: " + String(tenNotifSent));
  Serial.println("Notif3: " + String(tenNotifSent));
  Serial.println("NotifX: " + String(tenNotifSent));
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    if (command.startsWith("tenDaysNotif") && !tenNotifSent) {
      messageToSent = "tenDaysNotifSent";
      sendMessage(messageTen);
      ESP.restart();
    } else if (command.startsWith("fiveDaysNotif") && !fiveNotifSent) {
      messageToSent = "fiveDaysNotifSent";
      sendMessage(messageFive);
      ESP.restart();
    } else if (command.startsWith("threeDaysNotif") && !threeNotifSent) {
      messageToSent = "threeDaysNotifSent";
      sendMessage(messageThree);
      ESP.restart();
    }else if (command.startsWith("expiredNotif") && !expNotifSent) {
      messageToSent = "expiredNotifSent";
      sendMessage(messageExpired);
      ESP.restart();
    }

    if (command.startsWith("VendoOn")) {
      if (!vendoStatus) {
        Firebase.setBool("Vendo_Status", true);
      }
    }else if (command.startsWith("VendoOff")) {
      if (vendoStatus) {
        Firebase.setBool("Vendo_Status", false);
      }
    }

    if (command.startsWith("vendoExpDays: ")) {
      int sentDay = command.substring(14).toInt();
      if (sentDay != vendoExpDays) {
        Firebase.setInt("Expiration_Days", sentDay);
        ESP.restart();
      }
    } 
    if (command.startsWith("resetNotif")) {
      Firebase.setBool("tenDaysNotifSent", false);
      Firebase.setBool("fiveDaysNotifSent", false);
      Firebase.setBool("threeDaysNotifSent", false);
      Firebase.setBool("expiredNotifSent", false);
      ESP.restart();
    } 
    if (command.startsWith("restartNODEMCU")) {
      ESP.restart();
    } 
  }
 
}
 
void sendMessage(String messageContent){
  smtp.debug(1);
  smtp.callback(smtpCallback);

  ESP_Mail_Session session;
  session.server.host_name = SMTP_HOST;
  session.server.port = SMTP_PORT;
  session.login.email = AUTHOR_EMAIL;
  session.login.password = AUTHOR_PASSWORD;
  session.login.user_domain = "127.0.0.1";
  
  SMTP_Message message;
  message.sender.name = "Blue Ternate Vending Machine";
  message.sender.email = AUTHOR_EMAIL;
  message.subject = "Attention: Expiry Alert for Blue Ternate Inventory";
  
  FirebaseObject emails = Firebase.get("Emails");
  String obj = emails.getJsonVariant();
  DynamicJsonBuffer jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(obj);
  if (!root.success()) {
    Serial.println("parseObject() failed");
    return;
  }
  for (JsonObject::iterator it = root.begin(); it != root.end(); ++it) {
    const char* key = it->key;
    JsonObject& nestedObject = it->value;
    const char* email = nestedObject["Email"];
    message.addRecipient("Admin", email);
  }
  
  message.html.content = messageContent.c_str();
  message.html.charSet = "us-ascii";
  message.html.transfer_encoding = Content_Transfer_Encoding::enc_7bit;
  message.priority = esp_mail_smtp_priority::esp_mail_smtp_priority_low;
  // message.response.notify = esp_mail_smtp_notify_success | esp_mail_smtp_notify_failure | esp_mail_smtp_notify_delay;
  // message.addHeader("Message-ID: <abcde.fghij@gmail.com>");
  if (!smtp.connect(&session))
    return;
  if (!MailClient.sendMail(&smtp, &message))
    Serial.println("Error sending Email, " + smtp.errorReason());

  
}
void smtpCallback(SMTP_Status status)
{
  /* Print the current status */
  Serial.println(status.info());

  /* Print the sending result */
  if (status.success())
  {
    Serial.println("----------------");
    Serial.printf("Message sent success: %d\n", status.completedCount());
    Serial.printf("Message sent failled: %d\n", status.failedCount());
    Serial.println("----------------\n");
    struct tm dt;

    for (size_t i = 0; i < smtp.sendingResult.size(); i++)
    {
      /* Get the result item */
      SMTP_Result result = smtp.sendingResult.getItem(i);
      localtime_r(&result.timesstamp, &dt);

      Serial.printf("Message No: %d\n", i + 1);
      Serial.printf("Status: %s\n", result.completed ? "success" : "failed");
      Serial.printf("Date/Time: %d/%d/%d %d:%d:%d\n", dt.tm_year + 1900, dt.tm_mon + 1, dt.tm_mday, dt.tm_hour, dt.tm_min, dt.tm_sec);
      Serial.printf("Recipient: %s\n", result.recipients);
      Serial.printf("Subject: %s\n", result.subject);
    }
    Serial.println("----------------\n");
    if (messageToSent == "tenDaysNotifSent"){
      Firebase.setBool("tenDaysNotifSent", true);
    }else if (messageToSent == "fiveDaysNotifSent"){
      Firebase.setBool("fiveDaysNotifSent", true);
    }else if (messageToSent == "threeDaysNotifSent"){
      Firebase.setBool("threeDaysNotifSent", true);
    }else if (messageToSent == "expiredNotifSent"){
      Firebase.setBool("expiredNotifSent", true);
    }
  }
}
