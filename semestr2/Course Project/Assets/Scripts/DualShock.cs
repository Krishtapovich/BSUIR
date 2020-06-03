using UnityEngine;
using UnityEngine.InputSystem.DualShock;
using UnityEngine.SceneManagement;
using System;

public class DualShock : MonoBehaviour
{
    void Update()
    {
        try
        {
            DualShock4GamepadHID.current.SetLightBarColor(Color.green);
            if (DualShock4GamepadHID.current.leftTrigger.isPressed &&
                DualShock4GamepadHID.current.rightTrigger.isPressed)
            {
                SceneManager.LoadScene(SceneManager.GetActiveScene().name);
                Time.timeScale = 1f;
                
            }
            else if (DualShock4GamepadHID.current.leftStickButton.isPressed &&
                DualShock4GamepadHID.current.rightStickButton.isPressed)
            {
                Application.Quit();
            }
        }
        catch (NullReferenceException) { }
    }
}