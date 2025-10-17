import sys
import httpx

currency = sys.argv[1] if len(sys.argv) > 1 else "USD"
url = f"https://v6.exchangerate-api.com/v6/Your_Key/latest/{currency}"

try:
    response = httpx.get(url)
    response.raise_for_status()
    print(response.text)
except httpx.RequestError as e:
    print(f"فشل الاتصال بالسيرفر: {e}")
except httpx.HTTPStatusError as e:
    print(f"ا no req: {e}")
