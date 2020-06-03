using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.InputSystem.DualShock;
using System;

public class Play : MonoBehaviour
{
    public AudioSource song;

    void FixedUpdate()
    {
        try
        {
            DualShock();
        }
        catch (NullReferenceException) { }
    }

    void DualShock()
    {
        DualShock4GamepadHID.current.SetLightBarColor(Color.green);
        if (DualShock4GamepadHID.current.touchpadButton.isPressed)
        {
            PlayGame();
        }
        else if(DualShock4GamepadHID.current.leftStickButton.isPressed &&
            DualShock4GamepadHID.current.rightStickButton.isPressed)
        {
            QuitGame();
        }
    }

    public void PlayGame()
    {
        song.Stop();
        SceneManager.LoadScene("SampleScene");
    }

    public void QuitGame()
    {
        Application.Quit();
    }
}
