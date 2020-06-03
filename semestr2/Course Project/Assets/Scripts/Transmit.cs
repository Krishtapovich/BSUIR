using System;
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.InputSystem.DualShock;

public class Transmit : MonoBehaviour
{
    public GameObject pauseMenu;
    public GameObject deathMenu;
    public GameObject finishMenu;
    Animator anim;

    void Start()
    {
        anim = GetComponent<Animator>();
    }

    void DualShock()
    {
        if (DualShock4GamepadHID.current.leftStick.left.isPressed ||
            DualShock4GamepadHID.current.leftStick.right.isPressed)
        {
            anim.SetBool("isRunning", true);
        }
        else
        {
            anim.SetBool("isRunning", false);
        }

        if (DualShock4GamepadHID.current.buttonSouth.wasReleasedThisFrame)
        {
            anim.SetTrigger("Jump");
        }
    }

    void KeyBoard()
    {
        if (Keyboard.current.aKey.isPressed || Keyboard.current.dKey.isPressed ||
            Keyboard.current.leftArrowKey.isPressed || Keyboard.current.rightArrowKey.isPressed)
        {
            anim.SetBool("isRunning", true);
        }
        else
        {
            anim.SetBool("isRunning", false);
        }

        if (Keyboard.current.spaceKey.wasReleasedThisFrame)
        {
            anim.SetTrigger("Jump");
        }
    }

    void Update()
    {
        if (pauseMenu.activeInHierarchy == false && deathMenu.activeInHierarchy == false && finishMenu.activeInHierarchy == false)
        {
            try
            {
                DualShock();
            }
            catch (NullReferenceException)
            {
                KeyBoard();
            }
        }
    }
}