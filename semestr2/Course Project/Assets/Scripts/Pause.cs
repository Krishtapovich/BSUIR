using System;
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.InputSystem.DualShock;

public class Pause : MonoBehaviour
{
    bool gameIsPaused = false;
    public GameObject pauseMenu;
    AudioSource song;

    void Start()
    {
        song = GetComponent<AudioSource>();
        pauseMenu.SetActive(false);
    }

    bool DualShock()
    {
        try
        {
            return DualShock4GamepadHID.current.optionsButton.wasReleasedThisFrame;
        }
        catch (NullReferenceException)
        {
            return false;
        }
    }

    bool KeyBoard()
    {
        return Keyboard.current.escapeKey.wasReleasedThisFrame;
    }

    void Update()
    {
        if (DualShock() || KeyBoard())
        {
            if (gameIsPaused)
            {
                ResumeGame();
            }
            else
            {
                PauseGame();
            }
        }
    }

    public void ResumeGame()
    {
        gameIsPaused = false;
        Time.timeScale = 1f;
        song.UnPause();
        pauseMenu.SetActive(false);
    }

    void PauseGame()
    {
        gameIsPaused = true;
        Time.timeScale = 0f;
        song.Pause();
        pauseMenu.SetActive(true);
    }

    public void QuitGame()
    {
        song.Stop();
        Application.Quit();
    }
}