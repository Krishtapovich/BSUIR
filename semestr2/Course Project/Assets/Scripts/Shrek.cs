using System;
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.InputSystem.DualShock;

public class Shrek : MonoBehaviour
{
    float horizontalSpeed = 0.5f;
    float verticalImpulse = 6;
    float speedX;
    bool isGrouded;
    Rigidbody2D shrek;
    public GameObject pauseMenu;
    public GameObject deathMenu;
    public GameObject finishMenu;

    void Start()
    {
        shrek = GetComponent<Rigidbody2D>();
    }

    void DualShock()
    {
        if (DualShock4GamepadHID.current.leftStick.left.isPressed)
        {
            transform.eulerAngles = new Vector3(0, 180, 0);
            if (isGrouded == true)
            {
                speedX = horizontalSpeed / 3;
            }
            else
            {
                speedX = horizontalSpeed / 6;
            }
        }
        else if (DualShock4GamepadHID.current.leftStick.right.isPressed)
        {
            transform.eulerAngles = new Vector3(0, 0, 0);
            if (isGrouded == true)
            {
                speedX = horizontalSpeed / 3;
            }
            else
            {
                speedX = horizontalSpeed / 6;
            }
        }
        if (DualShock4GamepadHID.current.buttonSouth.wasReleasedThisFrame && isGrouded == true)
        {
            shrek.AddForce(new Vector2(0, verticalImpulse * 1.2f), ForceMode2D.Impulse);
            DualShock4GamepadHID.current.PauseHaptics();
        }
        transform.Translate(speedX, 0, 0);
        speedX = 0;
    }

    void KeyBoard()
    {
        if (Keyboard.current.aKey.isPressed || Keyboard.current.leftArrowKey.isPressed)
        {
            transform.eulerAngles = new Vector3(0, 180, 0);
            if (isGrouded == true)
            {
                speedX = horizontalSpeed / 3;
            }
            else
            {
                speedX = horizontalSpeed / 6;
            }
        }
        else if (Keyboard.current.dKey.isPressed || Keyboard.current.rightArrowKey.isPressed)
        {
            transform.eulerAngles = new Vector3(0, 0, 0);
            if (isGrouded == true)
            {
                speedX = horizontalSpeed / 3;
            }
            else
            {
                speedX = horizontalSpeed / 6;
            }
        }
        if (Keyboard.current.spaceKey.wasReleasedThisFrame && isGrouded == true)
        {
            shrek.AddForce(new Vector2(0, verticalImpulse * 1.2f), ForceMode2D.Impulse);
        }
        transform.Translate(speedX, 0, 0);
        speedX = 0;

    }

    void Update()
    {
        if(deathMenu.activeInHierarchy == true)
        {
            pauseMenu.SetActive(false);
            Time.timeScale = 0f;
        }

        if (pauseMenu.activeInHierarchy == false && deathMenu.activeInHierarchy == false && finishMenu.activeInHierarchy == false)
        {
            Time.timeScale = 1f;
            try
            {
                DualShock();
            }
            catch (NullReferenceException)
            {
                KeyBoard();
            }
        }

        if(shrek.transform.position.x < -1.7f)
        {
            shrek.transform.position = new Vector3(-1.7f, shrek.transform.position.y, shrek.transform.position.z);
        }
    }

    void OnTriggerStay2D(Collider2D collision)
    {
        if (collision.tag == "Ground")
        {
            try
            {
                DualShock4GamepadHID.current.PauseHaptics();
            }
            catch (NullReferenceException) { }
            finally
            {
                isGrouded = true;
            }
        }

        if (collision.tag == "Death")
        {
            try
            {
                DualShock4GamepadHID.current.PauseHaptics();
            }
            catch (NullReferenceException) { }
            finally
            {
                Time.timeScale = 0f;
                deathMenu.SetActive(true);
            }
        }

        if (collision.tag == "Finish")
        {
            try
            {
                DualShock4GamepadHID.current.PauseHaptics();
            }
            catch (NullReferenceException) { }
            finally
            {
                Time.timeScale = 0f;
                finishMenu.SetActive(true);
            }
        }
    }

    void OnTriggerExit2D(Collider2D collision)
    {
        if (collision.tag == "Ground")
        {
            try
            {
                DualShock4GamepadHID.current.SetMotorSpeeds(0.5f, 0.5f);
            }
            catch (NullReferenceException) { }
            finally
            {
                isGrouded = false;
            }
        }
    }
}