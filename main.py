import serial
import time
from pynput import keyboard

# Arduino bağlantısını kurun
arduino = serial.Serial('COM5', 9600, timeout=1)
time.sleep(5)  # Arduino'nun başlatılması için zaman tanıyın

def send_command_to_arduino(command):
    arduino.write((command + '\n').encode())
    print(f"{command} komutu gönderildi.")

def on_key_press(key):
    try:
        if key == keyboard.Key.media_volume_down:
            send_command_to_arduino("VOLUME_DOWN")
        elif key == keyboard.Key.media_volume_up:
            send_command_to_arduino("VOLUME_UP")
        elif key == keyboard.Key.f7:
            send_command_to_arduino("LEVEL")
        elif key == keyboard.Key.f3:
            send_command_to_arduino("POWER_TOGGLE")
    except AttributeError:
        pass

def on_key_release(key):
    pass

# Klavye dinleyicisini başlatın
keyboard_listener = keyboard.Listener(on_press=on_key_press, on_release=on_key_release)
keyboard_listener.start()

keyboard_listener.join()
