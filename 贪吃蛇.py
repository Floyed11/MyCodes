#gluttonous snake
import pygame
import sys
import random
from pygame.locals import *
pygame.init()
pygame.mixer.init()
pygame.mixer.music.load("bgm.mp3")
pygame.mixer.music.play(-1,0.0)
pygame.mixer.music.set_volume(0.25)
#定义颜色变量
black = pygame.Color(0,0,0)
white = pygame.Color(255,255,255)
red = pygame.Color(255,0,0)
grey = pygame.Color(150,150,150)
#定义游戏结束函数
def gameover():
    pygame.quit()
    sys.exit()
#定义主函数
def main():
    