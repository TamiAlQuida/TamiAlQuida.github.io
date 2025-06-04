import datetime
from astral.sun import sun
from astral import LocationInfo

latitude = 56.674  # Halmstad
longitude = 12.857 # Halmstad
city = LocationInfo("Halmstad", "Sweden", "Europe/Stockholm", latitude, longitude)
s = sun(city.observer, date=datetime.date(2025, 5, 29))


if __name__ == "__main__":

    print((
        f"Information for {city.name}/{city.region}\n"
        f"Timezone: {city.timezone}\n"
        f"Latitude: {city.latitude:.02f}; Longitude: {city.longitude:.02f}\n"
    ))

    print((
    f'Dawn:    {s["dawn"]}\n'
    f'Sunrise: {s["sunrise"]}\n'
    f'Noon:    {s["noon"]}\n'
    f'Sunset:  {s["sunset"]}\n'
    f'Dusk:    {s["dusk"]}\n'
))
