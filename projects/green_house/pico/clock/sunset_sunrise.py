import datetime
from astral.sun import sun
from astral import LocationInfo

latitude = 56.674  # Halmstad
longitude = 12.857 # Halmstad
city = LocationInfo("Halmstad", "Sweden", "Europe/Stockholm", latitude, longitude)
s = sun(city.observer, date=datetime.date.today(), tzinfo=city.timezone)

sunrise = s["sunrise"]
sunset = s["sunset"]

date_str = sunrise.strftime("%Y-%m-%d")
sunrise_str = sunrise.strftime("%H:%M:%S")
sunset_str = sunset.strftime("%H:%M:%S")



if __name__ == "__main__":

    print(
        f"Information for {city.name}/{city.region}\n"
        f"Timezone: {city.timezone}\n"
        f"Latitude: {city.latitude:.02f}; Longitude: {city.longitude:.02f}\n"
    )

    print(date_str)
    print(sunrise_str)
    print(sunset_str)


    with open("sunset_sunrise.txt", "w") as f:
        f.write(
            f"Date, Sunrise, Sunset \n"
            f"{date_str}, {sunrise_str}, {sunset_str}\n"
        )
