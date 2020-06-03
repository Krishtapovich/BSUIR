using UnityEngine;

public class Finish : MonoBehaviour
{
    public GameObject finishMenu;
    AudioSource song;

    void Start()
    {
        song = GetComponent<AudioSource>();
        finishMenu.SetActive(false);
    }

    void Update()
    {
        if (finishMenu.activeInHierarchy == true)
        {
            song.Stop();
        }
    }
}