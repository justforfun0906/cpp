from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from webdriver_manager.chrome import ChromeDriverManager
from selenium.webdriver.common.by import By
import time

# 自動下載並啟動 ChromeDriver
driver = webdriver.Chrome(service=Service(ChromeDriverManager().install()))

# 開啟網頁
driver.get("https://nthualb.url.tw/reservation/information/inlogin")
login_btn = driver.find_element(By.XPATH, '/html/body/table/tbody/tr[3]/td/table/tbody/tr/td[2]/table/tbody/tr[2]/td/table/tbody/tr[2]/td/table/tbody/tr[1]/td/button')
login_btn.click()

# 等待新標籤頁打開
time.sleep(2)

# 獲取所有標籤頁的句柄
handles = driver.window_handles

# 切換到新標籤頁
driver.switch_to.window(handles[1])

# 定位用戶名和密碼字段
username_field = driver.find_element(By.NAME, 'id')  # 修改為實際的名稱或其他選擇器
password_field = driver.find_element(By.NAME, 'password')  # 修改為實際的名稱或其他選擇器
captcha_field = driver.find_element(By.NAME, 'captcha')  # 修改為實際的名稱或其他選擇器
# 輸入用戶名和密碼
username_field.send_keys('112060002')  # 替換為實際的用戶名
password_field.send_keys('voqte4weFwag')  # 替換為實際的密碼
captcha_solution = input("Please enter the captcha solution: ")
captcha_field.send_keys(captcha_solution)

oauth_login_btn = driver.find_element(By.XPATH, '/html/body/div/div[2]/form/button')
# 提交表單
oauth_login_btn.click()
date = input("please enter the date: ")
reservation_url = "https://nthualb.url.tw/reservation/reservation?d="
reservation_url += date
#wait for the midnight
# while True:
#     if time.localtime().tm_hour == 0:
#         break
#     time.sleep(1)
driver.get(reservation_url)
# 保持瀏覽器開啟
input("Press Enter to close the browser...")
