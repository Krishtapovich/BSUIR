using UnityEngine;
using UnityEngine.SceneManagement;

public class Death : MonoBehaviour
{
    public GameObject deathMenu;
    AudioSource song;


    void Start()
    {
        deathMenu.SetActive(false);
        song = GetComponent<AudioSource>();
    }

    void Update()
    {
        if (deathMenu.activeInHierarchy == true)
        {
            song.Stop();
        }
    }

    public void RestartGame()
    {
        SceneManager.LoadScene(SceneManager.GetActiveScene().name);
        Time.timeScale = 1f;
        song.Play();
        deathMenu.SetActive(false);
    }

    public void QuitGame()
    {
        Application.Quit();
    }
}