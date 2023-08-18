import requests as req

def helper(l,r):
    url = "https://jsonmock.hackerrank.com/api/medical_records?page=1"
    res = req.get(url).json()
    pages = res['total_pages']
    per_page = res['per_page']
  
    cnt = 0
    sum = 0
    for i in range(1,pages+1):
        url = "https://jsonmock.hackerrank.com/api/medical_records?page="+str(i)
        res = req.get(url).json()
        for data in res['data']:
            if data['diagnosis']['name'] == 'Pulmonary embolism' and data['id'] == 2:
                sum += int(data['vitals']['pulse'])
                cnt+=1
    
    return sum//cnt

print(helper(120,160))