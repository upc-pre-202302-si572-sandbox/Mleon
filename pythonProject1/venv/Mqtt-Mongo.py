import datetime
import json
import paho.mqtt.client as paho
from pymongo import MongoClient
import threading


client = MongoClient('localhost')
db = client['pruebaiot']
col = db['Parametros_ambientales']

#ledcontrol = 0

def on_subscribe(client, userdata, mid, granted_qos):
    print("Subscribed: "+str(mid)+" "+str(granted_qos))

def on_message(client, userdata, msg):
    print(msg.topic+" "+str(msg.qos)+" "+str(msg.payload))
    documento = str(msg.payload)
    msgcount = len(str(documento))
    hora_actual = str(datetime.datetime.now())
    docIOT = documento[2:(msgcount - 2)] +', \"hora\": ' +'\"' + hora_actual + '\"' + '}'
    docIOT_dict = json.loads(docIOT)
    col.insert_one(docIOT_dict)

def user_input_thread():

    while True:
        ledcontrol = input('estado de ledcontrol: ')

        pub_msg = "{\"control\": " + ledcontrol + "}"
        client = paho.Client()
        client.connect('mqtt-dashboard.com', 1883)
        client.publish('topics/esp32_00001', pub_msg)
        if ledcontrol.lower() == 'q':
            break
user_input_thread = threading.Thread(target=user_input_thread)
user_input_thread.daemon = True
user_input_thread.start()

client = paho.Client()
client.on_subscribe = on_subscribe
client.on_message = on_message
client.connect('mqtt-dashboard.com', 1883)
client.subscribe('TOPIC/mobile_00001/RQ', qos=1)

client.loop_forever()


