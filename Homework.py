import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import collections

#Represent Location of Building
class Position:

  def __init__(self,x,y):
    self.__x=x
    self.__y=y

  def __str__(self):
      return 'x: ' + str(self.__x) + ' y: ' + str(self.__y)

  def get_x(self):
    return self.__x

  def get_y(self):
    return self.__y

  def __repr__(self):
    return str(self)

  def get_random_position_by_std(self, std):
    return Position(std*np.random.normal(0,1) + self.__x, std*np.random.normal(0,1) + self.__y)

class Building:

  __width = 20
  __length = 30

  def __init__(self,pos):
    self.__pos = pos
  
  #checking if the position inside the building limits
  def is_inside(self,position):
    return (abs(position.get_x() - self.__pos.get_x()) <= self.__width) and (abs(position.get_y() - self.__pos.get_y()) <= self.__length)

  def is_destroyed(self):
    return self.__is_destroyed

  def __str__(self):
    return str(self.__pos)+ ' , length: ' + str(self.__length) + '  width: ' + str(self.__width)

  def __repr__(self):
    return str(self)

class Base:

  def __init__(self,center_pos):
    self.__center_pos = center_pos
    self.__npm = center_pos.get_random_position_by_std(100)
    self.__buildings = []
    self.__num_of_destroyed = 0
    self.__destroyed_buildings = dict()

  def add_build(self,pos):
    building = Building(pos)
    self.__buildings.append(building)
    self.__destroyed_buildings[building] = 0

  def destroy_building_if_successed(self,position):
    for building in self.__buildings:
      if building.is_inside(position):
        self.__num_of_destroyed += 1
        self.__destroyed_buildings[building] += 1
      
  def is_all_destroyed(self):
    for building in self.__destroyed_buildings:
      if self.__destroyed_buildings[building] < 1:
        return False
    return True

  def clean(self):
    for building in self.__destroyed_buildings:
      self.__destroyed_buildings[building] = 0
    self.__num_of_destroyed = 0

  def change_npm(self):
    self.__npm = self.__center_pos.get_random_position_by_std(100)

  def num_of_destroyed(self):
    return self.__num_of_destroyed

  def get_num_of_buildings(self):
    return len(self.__buildings)

  def get_npm(self):
    return self.__npm

  def get_destroyted_building(self):
    return self.__destroyed_buildings

  def __repr__(self):
    return str(self)

  def __str__(self):
    for building in self.__buildings:
      print(building)    
    return ""      

base = Base(Position(0,0))
base.add_build(Position(-50,40))
base.add_build(Position(50,0))
base.add_build(Position(0,-30))
destroyed_builiding = [0] * base.get_num_of_buildings()
data = []
num_of_experiments = 100000
rg = range(1,num_of_experiments+1)
for i in rg:
  base.change_npm()
  for j in range(1,100):
    current_pos = base.get_npm().get_random_position_by_std(50)
    base.destroy_building_if_successed(current_pos)
    if base.num_of_destroyed() / base.get_num_of_buildings()  >= 0.8:     
      data.append(j)
      break
    
  base.clean() #clean all of the destroyed buildings

w = collections.Counter(data)
plt.bar(w.keys(), w.values())
print('Success Percent:', len(data)/num_of_experiments)
