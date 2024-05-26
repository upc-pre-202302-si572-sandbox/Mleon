import datetime
import json
import paho.mqtt.client as paho
import pyodbc
import threading

# Configuración de la conexión a la base de datos
server = 'LAPTOP-KU9RI5RI'
database = 'pruebaIOT'
username = 'sa'
password = 'Prueba123'



try:
    connection_string = f'DRIVER={{SQL Server}};SERVER={server};DATABASE={database};Trusted_Connection=yes;'
    conn = pyodbc.connect(connection_string)

except pyodbc.Error as ex:
    print(f"Error de conexión: {ex}")
    print(f"SQL State: {ex.args[0]}")
    print(f"Error Message: {ex.args[1]}")

def on_subscribe(client, userdata, mid, granted_qos):
    print("Subscribed: "+str(mid)+" "+str(granted_qos))

def on_message(client, userdata, msg):
    print(msg.topic+" "+str(msg.qos)+" "+str(msg.payload))
    documento = str(msg.payload)
    msgcount = len(str(documento))
    hora_actual = str(datetime.datetime.now())
    docIOT = documento[2:(msgcount - 2)] +', \"hora\": ' +'\"' + hora_actual + '\"' + '}'
    docIOT = docIOT.split()
    humidity = (docIOT[1])
    temp = (docIOT[3])
    print("Conexión exitosa con autenticación de Windows.")
    hora = ('F' + docIOT[5] + 'H' + docIOT[6])[:-1]

    # Preparar la consulta SQL con parámetros
    conn = pyodbc.connect(f'DRIVER={{SQL Server}};SERVER={server};DATABASE={database};UID={username};PWD={password}')
    sql_query = "INSERT INTO Parametros_ambientales (Temperatura, Humedad, Hora) VALUES (?,?, ?)"

    try:
        cursor = conn.cursor()
        cursor.execute(sql_query, (temp, humidity, hora,))
        conn.commit()
        print("Valores insertados exitosamente.")
    except Exception as e:
        conn.rollback()
        print("Error al insertar valores:", e)
    finally:
        conn.close()

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