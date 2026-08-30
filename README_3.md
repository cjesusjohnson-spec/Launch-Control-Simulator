
# Tesla Plaid-Inspired Launch Control Simulator (Arduino FSM)

A finite state machine (FSM) built on an Arduino Uno that simulates the launch sequence of Tesla's Model S Plaid "Drag Strip Mode" including Cheetah Stance preconditioning, a driver-input launch gate, and a triggered launch event. Status is displayed live on a 16x2 LCD alongside LED indicators for each stage.

## Inspiration

Tesla's Model S Plaid uses a pre-launch sequence to maximize traction and power delivery for its sub-2-second 0–60 mph runs:
1. Drive units are pre-cooled and the battery is warmed to its optimal temperature range
2. The front air suspension lowers ("Cheetah Stance") to reduce weight transfer off the front axle under hard acceleration
3. The driver holds brake + accelerator; releasing the brake triggers the launch

This project models that sequence not the real electrical/mechanical systems, but the *logic and state sequencing* behind it using LEDs, pushbuttons, and an LCD.

## States

| State | Trigger | Display |
|---|---|---|
| IDLE | Default / power-on | "IDLE" |
| Preconditioning | Start button pressed | "PRECONDITIONING" |
| Peak Performance | Auto-advance | "PEAK PERFORMANCE" |
| Cheetah Stance | Auto-advance | "CHEETAH STANCE" |
| Ready for Launch | Auto-advance | "READY FOR LAUNCH" |
| Launch | Brake + throttle held, brake released | "LAUNCHING" / "LAUNCHED" |

## Hardware

- Arduino Uno (Elegoo Uno R3)
- 5x LED (status indicators)
- 3x pushbutton (Start, Brake, Throttle) — wired with `INPUT_PULLUP`
- 16x2 LCD (LiquidCrystal library, parallel wiring)
- Resistors for LEDs

## What I learned

This project was my first time building a real finite state machine a system that's always in exactly one of a defined set of states, moving between them based on timed sequences and button input. Key concepts:

- **State sequencing** using `if` statements gated on button state, rather than a single `enum`/`switch` a simpler implementation of the same underlying FSM concept
- **Edge detection**: tracking a button's *previous* state to detect the exact moment of a press or release, rather than just its current state — critical for triggering the launch on brake *release*, not on brake being held
- **LCD control**: `lcd.clear()`, `lcd.setCursor()`, and `lcd.print()` to update status text in sync with each state transition
- Debugging real syntax and logic bugs independently: mismatched braces, missing `LOW` writes leaving LEDs stuck on, and conditional logic that fired continuously instead of once

## Code

See [`launch_control.ino`](./launch_control.ino) for the full sketch.

## Future improvements

- Replace `delay()`-based timing with `millis()` so button inputs aren't blocked during timed states
- Fix repeated re-triggering of the launch sequence while throttle is held after brake release
- Move to an explicit `enum`/`switch` state variable as the FSM scales

CIRCLED IS BUTTONS SIMULATING "BRAKE" AND "THROTTLE"
<img width="1280" height="959" alt="IMG_2915" src="https://github.com/user-attachments/assets/56baa814-cc1f-4c25-8410-fed25a7c018d" />
<img width="1280" height="959" alt="IMG_2916" src="https://github.com/user-attachments/assets/3038720a-7b2e-4d5e-8a66-2355eb55bb6d" />
<img width="1280" height="959" alt="IMG_2917" src="https://github.com/user-attachments/assets/bb585b6c-87a4-49a4-a959-f0ec299538d0" />
<img width="1280" height="959" alt="IMG_2918" src="https://github.com/user-attachments/assets/8d40efd1-ce8f-42b0-8561-8c98c320fd1e" />
<img width="1280" height="959" alt="IMG_2921" src="https://github.com/user-attachments/assets/28bf2216-bf05-4282-9fb4-48cc3849c0f5" />
