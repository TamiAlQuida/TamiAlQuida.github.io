import schemdraw
import schemdraw.elements as elm

with schemdraw.Drawing() as d:
    # 12V Power Supply
    d += elm.SourceV().label('12V Power Supply').length(2)
    d += elm.Line().right().length(1)
    d += elm.Dot().label('12V')
    
    # LM2596 Step-Down Converter (12V to 5V)
    d += elm.Line().right().length(2)
    d += elm.RBox(label='LM2596\n(12V to 5V)').length(2)
    d += elm.Line().right().length(2)
    d += elm.Dot().label('5V')
    d += elm.Line().down().length(1)
    d += elm.Ground()
    
    # Raspberry Pi Pico (Powered by 5V)
    d += elm.Line().right().length(2)
    d += elm.RBox(label='Raspberry Pi Pico').length(2)
    d += elm.Line().right().length(2)
    
    # Relay Module (5V Control, 12V Switching)
    d += elm.Line().down().length(2)
    d += elm.RBox(label='Relay Module\n(GND, 5V, Signal)').length(2)
    d += elm.Line().down().length(2)
    d += elm.Dot()
    d += elm.Line().down().length(1)
    d += elm.Ground()
    
    # GPIO Control from Pico to Relay
    d += elm.Line().left().length(2)
    d += elm.Dot()
    d += elm.Line().up().length(2)
    d += elm.RBox(label='GPIO Control').length(2)
    d += elm.Line().up().length(2)
    
    # Relay NO Terminal Controls 12V+ to Grow Light
    d += elm.Line().left().length(2)
    d += elm.RBox(label='Relay NO Terminal').length(2)
    d += elm.Line().left().length(2)
    d += elm.Dot().label('12V')
    d += elm.Line().up().length(1)
    d += elm.Line().left().length(2)
    
    # Grow Light Properly Connected
    d += elm.Line().right().length(4)
    d += elm.RBox(label='Grow Light').length(2)
    d += elm.Line().down().length(2)
    d += elm.Dot()
    d += elm.Line().down().length(1)
    d += elm.Ground()
    
    d.save('raspberry_pi_relay_diagram.svg')