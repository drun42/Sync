#!/bin/bash


while true; do
    # Move mouse using xdotool (usually pre-installed on 42 PCs)
    if command -v xdotool &> /dev/null; then
        # Get current position and move slightly
        eval $(xdotool getmouselocation --shell)
        xdotool mousemove $((X + 5)) $((Y + 5))
        sleep 0.1
        xdotool mousemove $X $Y
    else
        # Fallback: just send a harmless key using xdotool
        xdotool key Shift_L 2>/dev/null || {
            # If xdotool not found, use alternative method
            echo -n "." > /dev/null
        }
    fi
    
    echo -n "."  # Visual feedback
    sleep 60
done
